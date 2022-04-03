// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    size_t Factorial(size_t x)
    {
        size_t n = 1;
        for (size_t i = 1; i <= x; i++)
            n *= i;
        return n;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    std::cout << "The Factorial of " << argv[1] << " is " << s.Factorial(atoi(argv[1])) << std::endl;
    return 0;
}