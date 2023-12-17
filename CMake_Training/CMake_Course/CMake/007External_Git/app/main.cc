#include <iostream>
#include "my_lib.h"
#include "config.hpp"
#include <nlohmann/json.hpp>

int main()
{
    print_hello_world();

    std::cout << project_name << std::endl;
    std::cout << project_version << std::endl;

    std::cout << "JSON Lib Version : " 
    << NLOHMANN_JSON_VERSION_MAJOR << "."
    << NLOHMANN_JSON_VERSION_MINOR << "."
    << NLOHMANN_JSON_VERSION_PATCH << std::endl;

    return 0;
}
