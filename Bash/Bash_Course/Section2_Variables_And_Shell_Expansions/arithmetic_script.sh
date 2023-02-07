#!/bin/bash

x=4
y=2
echo $(($x + $y))		# we can also just write ((x + y))
echo $((x - y))
echo $((x * y))
echo $((x / y))
echo $((2 + 3 * 4))
echo $((4 ** 2))		# exponentiation
echo $((4 % 2))			# remainder

# Dealing with decimal numbers
# The "bc" command is used in Linux to deal with decimal point numbers, among other things
# we can do things like fractional division by using it with scale (number of digits after the decimal point) command and piping to bc
echo "scale=2; 5/2" | bc

# Note : exponentiation in the bc command is done like a^b, rather than a**b
echo "3^3" | bc