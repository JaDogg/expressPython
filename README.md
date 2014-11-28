expressPython
=============

expressPython : Express Python, A Small IDE

![Screenshot](http://lookpic.com/O/i2/11/H0H4YIQH.png) 

```
# Full API
# ---------------------------
# get method's have no parameters and others have one
#
# get_input   - get input textbox's text
# set_input   - set input textbox's text
# get_output  - get output textbox's text
# set_output  - get output textbox's text
# get_code    - get code textbox's text
# set_code    - set code textbox's text
# write_output- append to output box
# get_apppath - get exe path

# API Help/Code Sample
# ---------------------------

# get text from input box
# parameters - none
txt = get_input()

# change output box's text
# parameters - string
set_output("")

# append to output box
# does not add a new line
# parameters - string
write_output("Hi You,\n")

# get_apppath() -> get exe path
print ("expressPython.exe is at :", get_apppath())
```
