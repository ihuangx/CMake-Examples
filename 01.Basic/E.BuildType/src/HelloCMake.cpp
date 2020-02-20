#include "Message.hpp"

#include <cstdlib>
#include <iostream>

int main()
{
    Message sayHello("Hello, CMake World!");
    std::cout << sayHello << std::endl;

    Message sayGoodbye("Goodbye, CMake World!");
    std::cout << sayGoodbye << std::endl;

    return EXIT_SUCCESS;
}