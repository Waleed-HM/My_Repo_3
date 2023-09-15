# Makefile with notes :

# Makefiles should always be named "Makefile" exactly

# Targets (names for certain operations that we want to assign)

# /* One way to build the project is like this: */

# build:    # name for the operation 
# 	gcc main.c -c main.o			# compile main.c into an object file
# 	gcc my_lib.c -c my_lib.o		# compile my_lib.c into an object file
# 	gcc main.o my_lib.o -o main		# link both files into an executable

# /* Another way is by configuring it to make files separately: */
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