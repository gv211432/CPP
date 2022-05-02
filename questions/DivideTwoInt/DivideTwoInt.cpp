// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if ((dividend == 1 << 31) && (divisor == -1))
            return INT_MAX;

        // store negative sign for opposite signs of dividend and divisor
        bool sign = ((divisor >= 0) == (dividend >= 0)) ? true : false;

        // take the absolute values of the operators
        dividend = abs(dividend);
        divisor = abs(divisor);

        // this will sotre the result of the function
        int result = 0;

        // loop untill dividend - divisor becomes negative
        while (dividend - divisor >= 0)
        {
            int count = 0;
            // multiplying the divisor by 2 till is favours
            while (((dividend - (divisor << 1 << count)) <= INT_MAX) && ((dividend - (divisor << 1 << count) >= 0)))
                count++;

            result += 1 << count;
            dividend -= divisor << count;
        }
        return sign ? result : -result;
    }
};

int main(int arg, char *argv[])
{
    Solution s;

    std::cout << s.divide(-333333, -3) << std::endl;
    std::cout << s.divide(2147483648, 1) << std::endl;

    return 0;
}