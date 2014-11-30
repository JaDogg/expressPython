# Startup Script
# -------------------------------
# Express Python
#       Written by Bhathiya Perera
#

import sys
import io
import re

from express_api import get_input,set_input
from express_api import get_output,set_output
from express_api import get_code,set_code
from express_api import write_output,get_apppath

TXT = get_input()
___FAKE_STDIN = io.StringIO(TXT)
___REAL_STDIN = sys.stdin
sys.stdin = ___FAKE_STDIN
sys.argv = ["expressPython"]

