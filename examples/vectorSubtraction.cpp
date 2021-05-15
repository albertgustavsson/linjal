#include <iostream>
#include "Linjal.h"

int main(int argc, char const* argv[])
{
    Vector v1(3);
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;

    Vector v2(3);
    v2(0) = 4;
    v2(1) = 5;
    v2(2) = 6;

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << v1 - v2 << std::endl;
    return 0;
}
