#include <iostream>
#include <Matrix.h>

int main(int argc, char const *argv[])
{
    Matrix m(2, 3);
    m(0, 0) = 1;
    m(0, 1) = 2;
    m(0, 2) = 3;
    m(1, 0) = 4;
    m(1, 1) = 5;
    m(1, 2) = 6;
    std::cout << m << std::endl;
    std::cout << m*2 << std::endl;
    return 0;
}
