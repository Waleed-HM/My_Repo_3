#!/bin/bash

# In Linux, there are 3 types of data streams, each have their code number:
# Stream 0 = Standard Input (stdint)
# Stream 1 = Standard Output (Stdout)
# Stream 2 = Standard Error (stderr)

# Stream 0 usually comes from the keyboard. Redirection can alter that to something else like a text file
# Example: cat command usually hangs and waits for user input but we can do this instead:
cat < hello.txt
# This will take the content of hello.txt and use it as an input to the cat command

# Stream 1 is the standard output and usually goes to the command like terminal.
# Using the > operator, we can redirect it to something else like a text file:
echo "This is some output" > output.txt


# Stream 2 is the error output and it also goes to the command like terminal by default
# Similar to Stream 1, we can redirect it like this:
cd /root 2> error.txt

# Using the &> operator, we can send both Stream 1 and 2 where we want. 
# Example:
cd /root &> /dev/null
# Anything redirect to /dev/null gets immediately deleted (/dev/null is sometimes called the bitbucket)

# NOTE : the operator mentioned before delete the content of a file before putting the new info there
# If we wish to append the new information instead, we use double operators like : >>, 2>>, &>>