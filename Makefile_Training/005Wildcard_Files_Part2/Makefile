# Makefile with notes :

# Note : Variables can only be strings
# Note : Single or double quotes for variables names or values have no meaning to Make

# Those are important "kind of standard" variables
# CC : Program for compiling C programs; default cc
# CXX : Program for compiling C++ programs; default g++
# CFLAGS : Extra flags to give to the C compiler
# CXXFLAGS : Extra flags to give to the C++ compiler
# CPPFLAGS : Exta flags to give to the C preprocessor
# LDFLAGS : Extra flags to give to the linker

DEBUG = 1

C_STANDARD = c17
C_WARNINGS = -Wall -Wextra -Wpedantic

CC = gcc
CFLAGS =  $(C_WARNINGS) -std=$(C_STANDARD)
LDFLAGS = 							# This is usually important for the linker


# This is an example case for extending the CFLAGS based on whether we want to build for debug or for release
# So we when build we can do : make build DEBUG = 0/1
ifeq ($(DEBUG), 1)
CFLAGS += -g -O0
EXECUTABLE_NAME = mainDebug
else
CFLAGS += -O3
EXECUTABLE_NAME = mainRelease
endif

COMPILER_CALL = $(CC) $(CFLAGS)		# Remember : the $ is needed to access the value of a variable

# A list of source files using a wildcard function
C_SOURCES = $(wildcard *.c)

# A list of object files (useful when we have many source files)
# patsubst is a function to substitute patterns, in this case whichever ends with .c 
# to something with similar name and ends with .o
# based on the list named C_SOURCES
# This is necessary because normally object files don't exist before compilation
# so we can't just create a list directly like C_SOURCES
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

# Note : we can override some variable values when we call make 
# Ex : make build C_STANDARD=c11

# We can now use the defined COMPILER_CALL variable when needed everywhere in the file
build: $(C_OBJECTS)
	$(COMPILER_CALL) $(C_OBJECTS) $(LDFLAGS)-o $(EXECUTABLE_NAME)

execute:
	./$(EXECUTABLE_NAME)

clean:
	rm -f *.o
	rm -f $(EXECUTABLE_NAME)


###################
#### PATTERNS #####
###################

#Patterns are used when otherwise we need to add too many targets because we have too many source files

# $@: The file name of the target
# $<: The name of the first dependecy
# $^: The names of all prerequisites

#For every c file in our current directory, generate a corresponding object file with the same name (the %)
%.o: %.c
	$(COMPILER_CALL) -c $< -o $@


# The past two lines would translate to : (for main.c)
# main.o: main.c
# 	$(COMPILER_CALL) -c main.c -o main.o