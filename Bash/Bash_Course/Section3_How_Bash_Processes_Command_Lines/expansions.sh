#!/bin/bash

# Expansions are processed with a certain order
# Brace expansions happen first ... {1..3}
# Command expansions and arithmatic expansions have the same priority .. $name, $((5 + 2))

# Example:
name=Waleed
echo $name has {1..3} apples and $((5+2)) oranges
# Here, the {1..3} is processed first then $name and finally the $((5+2))

# Stages of expansions :
# 1 - Brace expansions
# 2 - Parameter, arithmetic, tilde expansions and command substitution 
# 3 - Word splitting
# 4 - Globbing