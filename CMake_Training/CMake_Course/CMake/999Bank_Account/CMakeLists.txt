cmake_minimum_required(VERSION 3.22)

project(
    Bank_Account
    VERSION 1.0.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD              17)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            OFF)


option(COMPILE_EXECUTABLE "Whether to compile the executable" ON)