# Cmake functions : function(function_name parameters)
function(add_git_submodule dir)

    # find_package searches for a package and errors out if it is not found (searches PATH variables)
    find_package(Git REQUIRED)

    if(NOT EXISTS ${dir}/CMakeLists.txt)
        execute_process(COMMAND ${GIT_EXECUTABLE}           # GIT_EXECUTABLE is a variable that is set by the find_package function
            submodule update --init --recursive -- ${dir}
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})        # PROJECT_SOURCE_DIR is a variable storing the path to the root directory of the project
    endif()

    add_subdirectory(${dir})

endfunction(add_git_submodule)