# Makefile with notes :

# Makefiles should always be named "Makefile" exactly

# Targets (names for certain operations that we want to assign)


build:    # name for the operation 
	gcc main.c -c main.o			# to create the obejct file
	gcc main.o -o main				# to link it to an executable

# note : we can also do those in one line : gcc main.c -o main

# important : operations commands must always be after a tab
# gcc : compiler name
# main.c : file to be compiled (source file)
# main.o : object file
# main : name of the executable

# important :
# The "make" command by itself performs the first target in the Makefile by default
# If we want it to perform a different target, we should specify its name after the make command

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