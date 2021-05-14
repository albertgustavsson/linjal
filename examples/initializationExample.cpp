#include <iostream>
#include "Matrix.h"

int main(int argc, char const* argv[])
{
    Matrix m(2, 3, 42.0f);
    std::cout << m << std::endl;
    return 0;
}
