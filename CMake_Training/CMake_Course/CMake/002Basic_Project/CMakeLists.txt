# define the minimum required version of CMake
cmake_minimum_required(VERSION 3.22)

# define the project : name of the project - version of the project - languages used
project(
    CppProjectTemplate
    VERSION 1.0.0
    LANGUAGES C CXX)

# here we add the libraries we have : name for the library - some key word - the source file of the library
add_library(Library STATIC my_lib.cc)

# here we define the executable name and the source file
add_executable(Output main.cc)

# we also need to link the library to the executable : executable name - some key word - library name
target_link_libraries(Output PUBLIC Library)

# to compile the project :
# 1 - create a build directory : mkdir build
# 2 - cd build
# 3 - instruct the cmake where to find the CMakeLists file : cmake ..
# 4 - build the project : cmake --build .
# 5 - run the executable


# we can also use something like this to define source files location and build location :
# cmake -S . -B ./build/
