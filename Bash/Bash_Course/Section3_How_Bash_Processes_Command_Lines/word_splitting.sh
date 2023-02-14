#!/bin/bash

# Word splitting is only performed on the results of unquoted:
# - Parameter expansions
# - Command substitutions
# - Arithmetic expansions

# Characters used to split words are governed by the IFS (internal field separator) variables: space,tab and new line
echo "${IFS@Q}"

numbers="1 2 3 4 5"

# This will create 5 files (named 1 to 5) because the argument is unquoted
#touch $numbers

# However, when the argument is quoted, words will not be split and one file named '1 2 3 4 5' will be created
#touch "$numbers"

# The comma is by default not in the IFS variables, so this will result in one file created
#numbers="1,2,3,4,5"
#touch $numbers

# However, we can change the value of IFS to have the comma as its variable
IFS=","
numbers="1,2,3,4,5"
touch $numbers

# In short, if we want something to be considered a single word, we should wrap that expansion in double quotes