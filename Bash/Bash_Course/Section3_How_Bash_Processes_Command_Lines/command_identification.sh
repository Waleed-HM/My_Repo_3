#!/bin/bash

# In bash, commands are separated and identified using control characters (such as the new line and ;)
# Usually, it's the invisible new line command that terminates a command, for example:
echo Hello world

# A command like this will not be interpreted as two echo commands for lack of a control character
echo a b c echo 1 2 3

# If we were to use ; it will be interpreted as two commands
echo a b c; echo 1 2 3