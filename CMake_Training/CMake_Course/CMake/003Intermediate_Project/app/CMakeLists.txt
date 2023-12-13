# here we define the executable name and the source file
# Note : if we want to keep this in the main CMake file, we can do so by writing app/main.cc inside the command
add_executable(Output main.cc)


# we also need to link the library to the executable : executable name - some key word - library name
target_link_libraries(Output PUBLIC Library)