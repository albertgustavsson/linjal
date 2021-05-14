#include <iostream>
#include "Matrix.h"

int main(int argc, char const* argv[])
{
    Matrix m(2, 3, 0);
    m(0, 0) = 1;
    m(1, 1) = 2;
    m(1, 2) = 3;
    std::cout << m << std::endl;
    std::cout << m.getTranspose() << std::endl;
    return 0;
}
