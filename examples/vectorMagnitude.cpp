#include <iostream>
#include "Linjal.h"

int main(int argc, char const* argv[])
{
    Vector v(3);
    v(0) = 1;
    v(1) = 2;
    v(2) = 3;
    std::cout << v << std::endl;
    std::cout << v.getMagnitude() << std::endl;
    return 0;
}
