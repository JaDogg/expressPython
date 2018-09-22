"""
Experimental Jedi Completions fetcher
"""
import os
import shlex
import sys
import io
import re
import site
import time
import subprocess


def get_completions(source, row, col, script_path=""):
    return []


# WHY:
# Only supports windows for now, we have full control cause we bundle everything!
if os.name == "nt":

    # WHY:
    # This is because we are embedding python and jedi tries to open expressPython.exe
    # Thinking it is python.exe
    try:
        import jedi
    except ImportError:
        pass
    else:
        d = os.path.dirname
        python_location = os.path.join(d(d(d(d(jedi.__file__)))), "python.exe")
        if os.path.exists(python_location):
            sys.executable = python_location

            def real(source, row, col, script_path=""):
                completions = []
                try:
                    script = jedi.Script(source, row + 1, col, script_path)
                    completion_objects = script.completions()
                    completions = [x.name for x in completion_objects]
                finally:
                    return completions

            get_completions = real
