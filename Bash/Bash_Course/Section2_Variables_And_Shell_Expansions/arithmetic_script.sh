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