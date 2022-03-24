// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

// debug correct and best method on leetcode
class Solution
{
public:
    int reverse(int x)
    {
        // variable for storing reversed integer
        int rev = 0;
        // loop till 'x' is reduced to 0 by dividing 10 in every iteration
        while (x != 0)
        {
            // pop will hold the units place's digit of the reducing 'x' integer
            int pop = x % 10;
            // reducing(trimming) the x from left side, one digit every iteration
            x /= 10;

            // if the reversed integer is overflowing

            // if reversed integer is in positive
            // if temp = rev.10 + pop; causes overflow then it must be that rev >= INTMAX/10
            // if rev > INTMAX/10, then temp = rev.10 + pop is gauranteed to overflow
            // if rev == INTMAX/10, the temp = rev.10 + pop, will overflow only
            // when pop > 7 and pop < -8 in negative case
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            // if the reversed integer is in negative
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;

            rev = rev * 10 + pop;
        }
        return rev;
    }
};

// debug not correct
class Solution2
{
public:
    int32_t reverse(int32_t x)
    {
        // variable for storing reversed integer
        int32_t rev = 0;
        // loop till 'x' is reduced to 0 by dividing 10 in every iteration
        while (x != 0)
        {
            // pop will hold the units place's digit of the reducing 'x' integer
            int32_t pop = x % 10;
            // reducing(trimming) the x from left side, one digit every iteration
            x /= 10;

            try
            {
                rev = rev * 10 + pop;
            }
            catch (const std::exception &e)
            {
                std::cout << "Error" << std::endl;
                return 0;
            }
        }
        if ((x > 0 && rev < 0) || (x < 0 && rev > 0))
            return 0;

        return rev;
    }
};

int main()
{
    Solution s;
    std::cout << s.reverse(1534236469) << std::endl;
    return 0;
}