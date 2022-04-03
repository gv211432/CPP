// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    size_t fib(size_t x) // O(logn)
    {
        if (x == 0 || x == 1)
            return 1;        // if factorial of 0 or 1 is asked
        else if (x % 2 == 0) // Number is even
            return ((2 * fib(x / 2)) + pow(x / 2, 2));
        else // Number is odd
            return fib(x - 1) + x;
    }

public:
    size_t Fibonacci(size_t n)
    {
        return fib(n);
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    if (atoi(argv[1]) > 1000000000 || atoi(argv[1]) < 0)
        std::cout << "No is out of Range!!" << std::endl;
    else
        std::cout << "Factorial of " << argv[1] << " is " << s.Fibonacci(atoi(argv[1])) << std::endl;
    return 0;
}
