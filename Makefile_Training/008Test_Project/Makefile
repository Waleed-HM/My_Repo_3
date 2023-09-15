MODE ?= release
ENABLE_WARNING ?= 1

INCLUDE_DIR = inc
SOURCE_DIR = src
BUILD_DIR = build
DEBUG_DIR = debug
RELEASE_DIR = release
EXECUTABLE_NAME = main

C_STANDARD = c17

ifeq ($(ENABLE_WARNING), 1)
C_WARNINGS = -Wall -Wextra -Wpedantic
else
C_WARNINGS =
endif

CC = gcc
CFLAGS = $(C_WARNINGS) -std=$(C_STANDARD)
CPPFLAGS = -I $(INCLUDE_DIR)
LDFLAGS =

ifeq ($(MODE), debug)
CFLAGS += -g -O0
CPPFLAGS += -D ENALBE_DEBUG
TARGET_DIR = $(BUILD_DIR)/$(DEBUG_DIR)
else
CFLAGS += -O3
TARGET_DIR = $(BUILD_DIR)/$(RELEASE_DIR)
endif

COMPILER_CALL = $(CC) $(CFLAGS) $(CPPFLAGS)

C_SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
C_OBJECTS = $(patsubst $(SOURCE_DIR)/%.c, $(TARGET_DIR)/%.o, $(C_SOURCES))


# /---------- Targets ------------/
all: create build

create:
	@mkdir -p $(TARGET_DIR)

build: create $(C_OBJECTS)
	@$(COMPILER_CALL) $(C_OBJECTS) $(LDFLAGS) -o $(TARGET_DIR)/$(EXECUTABLE_NAME)

execute:
	@./$(TARGET_DIR)/$(EXECUTABLE_NAME)

clean:
	@echo "Removing builds .."
	@rm -rf $(BUILD_DIR)

help:
	@echo "Use MODE option to specify desired build: "
	@echo "	- MODE=debug for debug build"
	@echo "	- MODE=release for release build"

$(TARGET_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(COMPILER_CALL) -c $< -o $@


.PHONY: all create build execute clean help