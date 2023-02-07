#!/bin/bash

# This is called command substitution, we save the output of a command into a variable
time=$(date +%H:%m:%S)
echo "Hello $USER, the time right now is $time"