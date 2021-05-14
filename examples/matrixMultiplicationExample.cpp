#include <iostream>
#include "Matrix.h"

int main(int argc, char const* argv[])
{
    Matrix m1(2, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    Matrix m2(3, 1);
    m2(0, 0) = 7;
    m2(1, 0) = 8;
    m2(2, 0) = 9;
    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    std::cout << m1 * m2 << std::endl;
    return 0;
}
