# Makefile with notes :

# Note : Variables can only be strings
# Note : Single or double quotes for variables names or values have no meaning to Make

# CC : Program for compiling C programs; default cc
# CXX : Program for compiling C++ programs; default g++
# CFLAGS : Extra flags to give to the C compiler
# CXXFLAGS : Extra flags to give to the C++ compiler
# CPPFLAGS : Exta flags to give to the C preprocessor
# LDFLAGS : Extra flags to give to the linker

DEBUG = 1

build: my_lib.o main.o 		# ----------> those are prerequisits, make will not attempt this target until they exist
	gcc main.o my_lib.o -o main

main.o:
# This will run as : gcc main.c -c main.o
	gcc main.c -c 	

my_lib.o:
# This will run as : gcc my_lib.c -c my_lib.o
	gcc my_lib.c -c 


execute:
	./main

clean:
	rm -f *.o
	rm -f main


# summary :

# general format for targets is:
# target name: prerequisites
#	commands (after a tab)

# prerequisites are file names, separated by spaces
# These files need to exist before the commands for the target can be run