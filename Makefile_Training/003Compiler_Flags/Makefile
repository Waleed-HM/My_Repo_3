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
EXECUTABLE_NAME = main

C_STANDARD = c17
C_WARNINGS = -Wall -Wextra -Wpedantic

CC = gcc
CFLAGS =  $(C_WARNINGS) -std=$(C_STANDARD)
LDFLAGS = 							# This is usually important for the linker


# This is an example case for extending the CFLAGS based on whether we want to build for debug or for release
# So we when build we can do : make build DEBUG = 0/1
ifeq ($(DEBUG), 1)
CFLAGS += -g -O0
else
CFLAGS += -O3
endif

COMPILER_CALL = $(CC) $(CFLAGS)		# Remember : the $ is needed to access the value of a variable

# Note : we can override some variable values when we call make 
# Ex : make build C_STANDARD=c11

# We can now use the defined COMPILER_CALL variable when needed everywhere in the file
build: my_lib.o main.o 		
	$(COMPILER_CALL) main.o my_lib.o $(LDFLAGS)-o $(EXECUTABLE_NAME)

main.o:
# This will run as : gcc main.c -c main.o
	$(COMPILER_CALL) main.c -c 	

my_lib.o:
# This will run as : gcc my_lib.c -c my_lib.o
	$(COMPILER_CALL) my_lib.c -c 


execute:
	./main

clean:
	rm -f *.o
	rm -f main


