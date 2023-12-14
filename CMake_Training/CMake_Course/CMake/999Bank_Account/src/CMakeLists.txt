set(LIBRARY_SOURCES
    "account.cpp"
    "account_ext.cpp"
    "helpers.cpp")

set(LIBRARY_HEADERS
    "../inc/account.h"
    "../inc/account_ext.h"
    "../inc/constants.h"
    "../inc/helpers.h")

set(EXECUTABLE_SOURCES
    "main.cpp")


add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})

target_include_directories(${LIBRARY_NAME} PUBLIC
    "../inc/")

add_executable(${EXECUTABLE_NAME} ${EXECUTABLE_SOURCES})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})