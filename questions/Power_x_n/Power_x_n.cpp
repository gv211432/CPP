// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    double helper(double x, int n) // utility function for recursion
    {
        if (n == 0)
            return 1;
        if (x == 0)
            return 0;

        double res = helper(x * x, n / 2); // 2^4 becomes 4^2, 2^10 becomes 4^5, 3^20 becomes 9^10 becomes 81^5 and so on..
        return (n % 2) ? res * x : res;    // if power is odd multiply by same no. (ie. 2^5 = 2^4 * 2)
    }

public:
    double myPow(double x, int n)
    {
        double res = helper(x, n);     // O(logN)
        return n >= 0 ? res : 1 / res; // if power is +ve return res if -ve return 1/res
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    std::cout << s.myPow(-2, 6) << std::endl;
    // std::cout << 2 / 2 << std::endl;
    // std::cout << 2 % 2 << std::endl;
    return 0;
}
