# here we add the libraries we have : name for the library - some key word - the source file of the library
# Note : if we want to keep this in the main CMake file, we can do so by writing src/my_lib.cc inside the command
add_library(${LIBRARY_NAME} STATIC my_lib.cc)

# we need to instruct CMake where to find the header files of the library
target_include_directories(${LIBRARY_NAME} PUBLIC "./")