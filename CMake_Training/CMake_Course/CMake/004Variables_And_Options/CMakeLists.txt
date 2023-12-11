# define the minimum required version of CMake
cmake_minimum_required(VERSION 3.22)

# define the project : name of the project - version of the project - languages used
project(
    CppProjectTemplate
    VERSION 1.0.0
    LANGUAGES C CXX)

# overwriting some CMake variables
# use C++17
set(CMAKE_CXX_STANDARD              17)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)     # ----> The compiler version must have fully implemented standard
set(CMAKE_CXX_EXTENSIONS            OFF)    # ----> gcc and g++ have some extended features not in the C/C++ standards - don't enable them

# we can created variables and use their names in the project
# common practice is to use all caps for variable names
# Variable name - value
set(LIBRARY_NAME "Library")
set(EXECUTABLE_NAME "Output")

# some options
# option name - optional hint text - value
option(COMPILE_EXECUTABLE "Whether to compile the executable" ON)

# We need to add subdirectories (where sub CMake files are located)
add_subdirectory(src)
if(COMPILE_EXECUTABLE)
    add_subdirectory(app)
else()
    message("Executable not compiled !")
endif()

# -----------------------------------------------------------------------------------------------

# to compile the project :
# 1 - create a build directory : mkdir build
# 2 - cd build
# 3 - instruct the cmake where to find the CMakeLists file : cmake ..
# 4 - build the project : cmake --build .
# 5 - run the executable


# we can also use something like this to define source files location and build location :
# cmake -S . -B ./build/
