# Startup script
# -------------------------------
# ELSEBA Python Runner
#       Written by Bhathiya Perera
#
#
import sys
import io
import re
from expressApi import get_input,set_input
from expressApi import get_output,set_output
from expressApi import get_code,set_code
from expressApi import write_output,get_apppath

# stdin/stderr/stdout is redirected to textboxes
___fake_stdin = io.StringIO(get_input())
___real_stdin = sys.stdin
sys.stdin = ___fake_stdin
sys.argv = ["PyRun"]

