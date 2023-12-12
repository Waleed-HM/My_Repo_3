#include <iostream>
#include "my_lib.h"
#include "config.hpp"

int main()
{
    print_hello_world();

    std::cout << project_name << std::endl;
    std::cout << project_version << std::endl;

    return 0;
}
