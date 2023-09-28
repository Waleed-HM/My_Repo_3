MODE ?= release				# default mode
ENABLE_WARNING ?= 0

INCLUDE_DIR = inc
SOURCE_DIR = src
BUILD_DIR = build
EXECUTABLE_NAME = app

CXX_STANDARD = c++11

ifeq ($(ENABLE_WARNING), 1)
CXX_WARNINGS = -Wall -Wextra -Wpedantic
else
CXX_WARNINGS =
endif

CXX = g++
CXXFLAGS = $(CXX_WARNINGS) -std=$(CXX_STANDARD)
CPPFLAGS = -I $(INCLUDE_DIR)
LDFLAGS =

ifeq ($(MODE), debug)
CXXFLAGS += -g -O0
CPPFLAGS += -D ENALBE_DEBUG
#TARGET_DIR = $(BUILD_DIR)/$(DEBUG_DIR)
else
CXXFLAGS += -O3
#TARGET_DIR = $(BUILD_DIR)/$(RELEASE_DIR)
endif

TARGET_DIR = $(BUILD_DIR)

COMPILER_CALL = $(CXX) $(CXXFLAGS) $(CPPFLAGS)

CXX_SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
CXX_OBJECTS = $(patsubst $(SOURCE_DIR)/%.cpp, $(TARGET_DIR)/%.o, $(CXX_SOURCES))


# /---------- Targets ------------/
all: create build

create:
	@echo "Creating build directory .."
	@mkdir -p $(TARGET_DIR)

build: create $(CXX_OBJECTS)
	@echo "Building project .."
	@$(COMPILER_CALL) $(CXX_OBJECTS) $(LDFLAGS) -o $(TARGET_DIR)/$(EXECUTABLE_NAME)

execute:
	@./$(TARGET_DIR)/$(EXECUTABLE_NAME)

clean:
	@echo "Removing builds .."
	@rm -rf $(BUILD_DIR)

help:
	@echo "Use MODE option to specify desired build: "
	@echo "	- MODE=debug for debug build"
	@echo "	- MODE=release for release build"

$(TARGET_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(COMPILER_CALL) -c $< -o $@


.PHONY: all create build execute clean help