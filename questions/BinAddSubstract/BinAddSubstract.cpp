// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Add(int x, int y)
    {
        // carry should be unsigned to deal with -ve numbers
        // carry now contains common set bits of x and y
        // Sum of bits of x and y where at least one of the bits is not set
        // Carry is shifted by one so that adding it to x gives the required sum

        while (y != 0) // Iterate till there is no carry
        {
            unsigned carry = x & y;    // declaring and initializing carry
            x = x ^ y, y = carry << 1; // x = x XOR y then y = carry left shift by 1
        }
        return x;
    }

    int AddRecursive(int x, int y) // same as above but recursive, uses stack memory of os
    {
        return (y == 0) ? x : AddRecursive(x ^ y, (unsigned)(x & y) << 1);
    }

    int Subtract(int x, int y)
    {

        // borrow contains common set bits of y and unset bits of x
        // Subtraction of bits of x and y where at least one of the bits is not set
        // Borrow is shifted by one so that subtracting it from x gives the required sum

        // Iterate till there is no borrow
        while (y != 0)
        {
            int borrow = (~x) & y;
            x = x ^ y, y = borrow << 1;
        }
        return x;
    }

    int SubRecursive(int x, int y)
    {
        return (y == 0) ? x : SubRecursive(x ^ y, (unsigned)((~x) & y) << 1);
    }

    // Dividing without actual division multiplication and modulus
    int divide(int dividend, int divisor)
    {
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        dividend = abs(dividend), divisor = abs(divisor);

        int quotient = 0;
        while (dividend >= divisor)
            dividend -= divisor, ++quotient;

        return quotient * sign;
    }
};

int main(int arg, char *argv[])
{
    Solution s;

    std::cout << s.Add(40, 2) << std::endl;
    std::cout << s.AddRecursive(90, 880) << std::endl;
    std::cout << s.Subtract(80, 50) << std::endl;
    std::cout << s.Subtract(80, 50) << std::endl;
    std::cout << s.divide((1 << 31), -1) << std::endl;
    std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}