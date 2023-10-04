# Name of component to be tested
COMPONENT_NAME = account

# Variables to be defined here are mentioned in cpputest_folder/build/MakefileWorker.mk

# Dynamically generate absoulute paths
MAKEFILE_DIR = $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
PROJECT_DIR = $(realpath $(MAKEFILE_DIR)../..)
INC_DIR = $(PROJECT_DIR)/inc
SRC_DIR = $(PROJECT_DIR)/src
TEST_DIR = $(PROJECT_DIR)/tests

# Location of CppUTest (if not already set)
CPPUTEST_HOME ?= $(PROJECT_DIR)/../../Unit_Testing_Frameworks/cpputest-4.0

# Include and source files for component under test
INCLUDE_DIRS = $(INC_DIR)
SRC_DIRS = $(SRC_DIR)

# Include CppUTest header files
INCLUDE_DIRS += $(CPPUTEST_HOME)/include

# Directories containing the unit tests
TEST_SRC_DIRS = $(TEST_DIR)/$(COMPONENT_NAME)

# Run MakefileWorker.mk with the variables set in this Makefile
include $(CPPUTEST_HOME)/build/MAkefileWorker.mk