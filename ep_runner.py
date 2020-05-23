"""
expressPython Runner Script
- Bhathiya Perera
"""

# ==========================================================================================
#                               IMPORTS, SETUP express_api API
# ==========================================================================================

import os
import shlex
import sys
import io
import re
import site
import time
import subprocess
from threading import Thread
from queue import Queue
import queue
from datetime import datetime

from express_api import get_input, set_input
from express_api import get_output, set_output
from express_api import get_code, set_code
from express_api import write_output, get_apppath
from express_api import set_search_regex, interrupt_requested

KILL_INTERRUPT = 1
UNKNOWN_INTERRUPT = -1
DEFAULT_TIMEOUT = 1000
DEFAULT_ENCODING = "utf-8"
NASTY_CHARS = '()%!^"<>&|'
DEBUG_PRINT = False

CODE = get_code()
CODE_LINES = CODE.splitlines()
TXT = get_input()

___FAKE_STDIN = io.StringIO(TXT)
___REAL_STDIN = sys.stdin
sys.stdin = ___FAKE_STDIN
sys.stdin.fileno = lambda: 1222
sys.argv = ["expressPython"]


def cls(*args, **kwargs):
    """
    Clear Output
    """
    set_output("")


def exit(*args, **kwargs):
    """
    Pseudo exit
    """
    pass


def quit(*args, **kwargs):
    """
    Pseudo quit function
    """
    pass


# ==========================================================================================
#                                    UTILITIES
# ==========================================================================================

HIDDEN_PROCESS_START = None
if os.name == "nt":
    HIDDEN_PROCESS_START = subprocess.STARTUPINFO()
    HIDDEN_PROCESS_START.dwFlags = (
            subprocess.CREATE_NEW_CONSOLE | subprocess.STARTF_USESHOWWINDOW
    )
    HIDDEN_PROCESS_START.wShowWindow = subprocess.SW_HIDE


def escape_shell(single_arg):
    """
    Escape a single shell argument for bash/sh or cmd.exe
    :param single_arg:
    :return: escaped string
    """
    if os.name == "nt":
        return escape_win(single_arg)
    else:
        return escape_nix(single_arg)


def cat_cmd(filename):
    if os.name == "nt":
        return "type " + escape_win(filename)
    else:
        return "cat" + escape_nix(filename)


def sys_kill(pid):
    try:
        if os.name == "nt":
            shell_execute("taskkill /PID " + str(pid) + " /F")
        else:
            shell_execute("kill -9 " + str(pid))
    except:
        if DEBUG_PRINT:
            raise


def shell_execute(shell_cmd):
    subprocess.run(shell_cmd, shell=True)

# WHY: "-u" ensure that python's output is unbuffered so we can get it as soon as it appears in our editor
def python_cmd(filename):
    if CODE.startswith("#!"):
        first_line = CODE_LINES[0]
        python = first_line[2:].strip()
        return list(shlex.split(python)) + [escape_shell(filename)]
    elif os.name == "nt":
        return ["python", "-u", escape_win(filename)]
    elif os.name == "posix":
        return ["python3.8", "-u", filename]
    else:
        return ["python3.8", "-u", escape_nix(filename)]


def escape_nix(s):
    return "'" + s.replace("'", "'\\''") + "'"


def escape_win(arg):
    if not arg or re.search(r'(["\s])', arg):
        arg = '"' + arg.replace('"', r"\"") + '"'

    return double_escape_win(arg)


def double_escape_win(arg):
    replace_regex = re.compile(
        "(" + "|".join(re.escape(char) for char in list(NASTY_CHARS)) + ")"
    )
    replace_map = dict((char, "^%s" % char) for char in NASTY_CHARS)

    def escape_nasty_chars(m):
        char = m.group(1)
        return replace_map[char]

    return replace_regex.sub(escape_nasty_chars, arg)


def debug_print(*args, **kwargs):
    if not DEBUG_PRINT:
        return
    date = f"{datetime.now():%Y%m%d%H%M%S%z}"
    print(date + "| expressPython | ", end="")
    print(*args, **kwargs)


# ==========================================================================================
#                                    CODE EXECUTORS
# ==========================================================================================


class CodeExecutor:
    """
    A simple code executor, others should derive from this class

    How does this executes the command
    1) If `#!` is at the beginning of the first line then that that python version will be used
    2) Executes a pipe with INPUT and reads STDERR, STDOUT
    3) Support killing the process on interrupt

    Methods needed for subclasses:
        .name - property, static, name of the class
        .run(*args) - execute python code
        .kill() - kill python code being run
        .clean() - clean anything that is not required
        .done - execution successful ?
    """

    def __init__(self):
        self.cur_date = f"{datetime.now():%Y%m%d%H%M%S%z}"
        self.code_path = os.path.abspath(
            os.path.join(
                os.path.dirname(get_apppath()), "code.ep." + self.cur_date + ".py"
            )
        )
        self.data_path = os.path.abspath(
            os.path.join(
                os.path.dirname(get_apppath()), "data.ep." + self.cur_date + ".dt"
            )
        )
        self.python = None
        self.interrupt = False
        self.done = False

    @staticmethod
    @property
    def name():
        return "normal"

    def run(self, *args):
        """
        Run code executor
        """
        self.write_files()

        command = python_cmd(self.code_path)
        debug_print(command)

        self.python = subprocess.Popen(
            command,
            shell=False,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            startupinfo=HIDDEN_PROCESS_START,
        )

        self.start_workers()

    def write_files(self):
        with open(self.data_path, "w+") as data:
            data.write(TXT)
            data.flush()
        with open(self.code_path, "w+") as code:
            code.write(get_code())
            code.flush()

    def start_workers(self):
        store = Queue()
        writer_thread = Thread(
            target=self.writer, args=[self.python.stdin], daemon=True
        )
        writer_thread.start()
        time.sleep(0.01)
        reader_thread = Thread(
            target=self.reader, args=[self.python.stdout, store], daemon=True
        )
        reader_thread.start()
        # WHY:
        # Make the read work faster in a different thread
        while True:
            if self.interrupt:
                break
            try:
                line = store.get(block=False, timeout=1)
                if line is None:
                    break
                write_output(line.decode(DEFAULT_ENCODING))
            except queue.Empty:
                pass
        self.done = True

    def reader(self, pipe, store):
        """
        Thread method. reads stdin/stdout
        :param pipe: PIPE
        :param store: Queue
        """
        debug_print("READER...")
        try:
            with pipe:
                for line in iter(pipe.readline, b""):
                    if self.interrupt:
                        return
                    store.put(line)
        finally:
            store.put(None)

    def writer(self, pipe):
        """
        Thread method. writes to stdin
        :param pipe:
        :return:
        """
        debug_print("WRITER")
        try:
            with pipe:
                for line in TXT.splitlines():
                    if self.interrupt:
                        return
                    pipe.write(line.encode(DEFAULT_ENCODING))
                    pipe.write(os.linesep.encode(DEFAULT_ENCODING))
        finally:
            pass

    def kill(self):
        pid = self.python.pid
        debug_print("Killing", pid, "...")
        self.python.terminate()
        time.sleep(1)
        sys_kill(pid)
        self.interrupt = True

    def clean(self):
        if os.path.exists(self.code_path):
            os.remove(self.code_path)
        if os.path.exists(self.data_path):
            os.remove(self.data_path)


EXECUTORS = {CodeExecutor.name: CodeExecutor}

# ==========================================================================================
#                                       RUN
# ==========================================================================================


debug_print("Starting ...")
executor = CodeExecutor()
interrupted = UNKNOWN_INTERRUPT


def runner(executor_):
    executor_.run()


try:
    executor_t = Thread(target=runner, args=[executor], daemon=True)
    executor_t.start()
    while not executor.done:
        time.sleep(1)
        interrupted = interrupt_requested()
        if interrupted == KILL_INTERRUPT:
            debug_print("expressPython:Terminating ...")
            try:
                executor.kill()
            except:
                if DEBUG_PRINT:
                    raise
            finally:
                pass
            break
except (SystemError, KeyboardInterrupt) as ex:
    try:
        debug_print("Stopping ....")
    except KeyboardInterrupt:
        debug_print("Interrupted!")
finally:
    try:
        try:
            executor.clean()
        except:
            if DEBUG_PRINT:
                raise
        finally:
            pass
        if not interrupted:
            try:
                executor.kill()
            except:
                if DEBUG_PRINT:
                    raise
            finally:
                pass
    except KeyboardInterrupt:
        debug_print("Interrupted!")
