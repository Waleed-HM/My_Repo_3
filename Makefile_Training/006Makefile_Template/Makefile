# Makefile with notes :

# Those are important "kind of standard" variables
# CC : Program for compiling C programs; default cc
# CXX : Program for compiling C++ programs; default g++
# CFLAGS : Extra flags to give to the C compiler
# CXXFLAGS : Extra flags to give to the C++ compiler
# CPPFLAGS : Exta flags to give to the C preprocessor
# LDFLAGS : Extra flags to give to the linker

DEBUG = 1
ENABLE_WARNING = 1
WARNINGS_AS_ERRORS = 0

INCLUDE_DIR = inc
SOURCE_DIR = src
BUILD_DIR = build

C_STANDARD = c17

ifeq ($(ENABLE_WARNING), 1)
C_WARNINGS = -Wall -Wextra -Wpedantic
else
C_WARNINGS = 
endif

ifeq ($(WARNINGS_AS_ERRORS), 1)
C_WARNINGS += -Werror				# stops the compilation if warnings are found
endif

CC = gcc
CFLAGS =  $(C_WARNINGS) -std=$(C_STANDARD)
CPPFLAGS = -I $(INCLUDE_DIR)		# A pre-processor flag to let the compiler know where to look for header files
LDFLAGS = 							


# This is an example case for extending the CFLAGS based on whether we want to build for debug or for release
# So we when build we can do : make build DEBUG = 0/1
ifeq ($(DEBUG), 1)
CFLAGS += -g -O0
EXECUTABLE_NAME = mainDebug
else
CFLAGS += -O3
EXECUTABLE_NAME = mainRelease
endif

COMPILER_CALL = $(CC) $(CFLAGS) $(CPPFLAGS)


C_SOURCES = $(wildcard $(SOURCE_DIR)/*.c)

C_OBJECTS = $(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SOURCES))

###################
#### TARGETS ######
###################

build: create $(C_OBJECTS)
	$(COMPILER_CALL) $(C_OBJECTS) $(LDFLAGS)-o $(BUILD_DIR)/$(EXECUTABLE_NAME)

execute:
	./$(BUILD_DIR)/$(EXECUTABLE_NAME)

clean:
# 	rm -f $(BUILD_DIR)/*.o
# 	rm -f $(BUILD_DIR)/$(EXECUTABLE_NAME)
	rm -rf $(BUILD_DIR)

create:
	mkdir -p $(BUILD_DIR)			# This target is to create the build directory in case it doesn't exist

###################
#### PATTERNS #####
###################

#Patterns are used when otherwise we need to add too many targets because we have too many source files
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(COMPILER_CALL) -c $< -o $@


# The past two lines would translate to : (for main.c)
# main.o: main.c
# 	$(COMPILER_CALL) -c main.c -o main.o

###################
#### PHONY  #######
###################
# With .PHONY we list all targets that don't correspond to a file name
.PHONY: create build execute clean