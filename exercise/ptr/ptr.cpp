// Main file of the Project
#include <iostream>

void addOne(int *a)
{
    *a = *a + 1;
    std::cout << *a << std::endl;
}

int main(int arg, char *argv[])
{
    int a = 10;
    int &b = a;
    int &c = b;

    std::cout << &a << std::endl;
    std::cout << &b << std::endl;
    std::cout << &c << std::endl;

    b = b + 1;
    std::cout << b << std::endl;
    std::cout << a << std::endl;

    // int *ptrA = &a;

    // int **pTpA = &ptrA;

    // std::cout << &ptrA << std::endl;
    // std::cout << **pTpA << std::endl;

    // addOne(&a);

    // std::cout << a << std::endl;

    // std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}