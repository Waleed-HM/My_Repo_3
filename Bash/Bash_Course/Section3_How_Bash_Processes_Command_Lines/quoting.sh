#!/bin/bash

# In bash, some characters are special characters ( such as $ and & )
# They would interfere with interpreting a piece of text

# There are some ways around that like using the "\" character to negate one character after it
# That means it will be interpreted as text
# Example:
echo Waleed \& kotaiba

# When we have a string of text containing multiple special character, it's easier to using single quotes
# Example: ( the \ is the special character here )
filepath='C:\Users\Waleed\Documents'
echo $filepath

# The doulbe quotes negate the effect of all special characters within them excpet the $ character
# In this example, we need an extra \ before the $ to negate the effect of the first \
# to avoid having the $ effect negated 
filepath2="C:\Users\\$USER\Documents"
echo $filepath2