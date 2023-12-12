# we can add executable source files to lists that we can pass later
set(EXECUTABLE_SOURCES
    "main.cc")

# here we define the executable name and the source file
# Note : if we want to keep this in the main CMake file, we can do so by writing app/main.cc inside the command
add_executable(${EXECUTABLE_NAME} ${EXECUTABLE_SOURCES})


# we also need to link the library to the executable : executable name - some key word - library name
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})