cmake_minimum_required(VERSION 3.22)

project(
    Bank_Account
    VERSION 1.0.0
    LANGUAGES C CXX
)


set(CMAKE_CXX_STANDARD              17)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            OFF)


set(LIBRARY_NAME "Accounts")
set(EXECUTABLE_NAME "App")

option(DEBUG_BUILD      ON)

if(DEBUG_BUILD)
    set(CMAKE_BUILD_TYPE        DEBUG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Output/Debug)
else()
    set(CMAKE_BUILD_TYPE        RELEASE)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Output/Release)
endif()



#add_subdirectory(inc)
add_subdirectory(src)


option(COMPILE_EXECUTABLE "Whether to compile the executable" ON)