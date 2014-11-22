# Startup script
# -------------------------------
# ELSEBA Python Runner - Bhathiya Perera
#
#

# API access
from emb import get_input,set_output,write_output

# create dump function
try:
    from cStringIO import StringIO
except:
    from StringIO import StringIO

def dump(*something):
    """append something to output"""
    output = StringIO()
    for onething in something:
        print >>output, onething
    converted_str = output.getvalue()
    output.close()
    write_output(converted_str)
# -------------------------------

