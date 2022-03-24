//Main file of the Project
#include <iostream>

int main(int arg, char *argv[])
{
    // & this operator gives the address of self
    // * this operator resolves the value, of the address that is stored as a value, in self
    int x = 5;     // say 0x55 = 5
    int *ptr = &x; // then 0x56 = 0x55
    // address of others
    std::cout << ptr << std::endl;  // 0x55
    std::cout << *ptr << std::endl; // 5
    // address of self
    std::cout << &ptr << std::endl; // 0x56
    // address of someone, who is keepin address of someone;
    int **q = &ptr;                // 0x57 = 0x56
    std::cout << *q << std::endl;  // 0x56
    std::cout << **q << std::endl; // 5

    int ***v = &q;
    std::cout << *v << std::endl;  // 0x57
    std::cout << **v << std::endl; // 0x56
    std::cout << **v << std::endl; // 5
    // std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}