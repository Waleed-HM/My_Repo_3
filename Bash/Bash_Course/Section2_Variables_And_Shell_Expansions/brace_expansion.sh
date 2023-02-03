#!/bin/bash


# Brace expansion is done using curly braces, such as: (no spaces)(any type of items can be used, this is called String List)
echo {jan,feb,mar,apr,may,jun}

# We can also do something like this but start and end must be of the same type (This is called Range List)
echo {1..20}

# Any order can be used as well
echo {15..7}
echo {z..a}

# We can control the step like this
echo {1..60..3}

# Brace expansion can be done for things like creating directories
#mkdir month_{01..04}

# And also creating files within directories
#touch month_{01..04}/day{01..31}.txt