# Startup script
# -------------------------------
# ELSEBA Python Runner
#       Written by Bhathiya Perera
#
#

# API access
from emb import get_input,set_output,write_output,get_apppath

try:
    from cStringIO import StringIO
except:
    from StringIO import StringIO

def dump(*something):
    """Append something to output"""
    output = StringIO()
    for onething in something:
        print >>output, onething
    converted_str = output.getvalue()
    output.close()
    write_output(converted_str)

def clear_output():
    """Clear output textbox"""
    write_output("")
# -------------------------------

