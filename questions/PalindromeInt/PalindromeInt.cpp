// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // if given number is negative or
        // multiple of 10 (eg. 100, 400, 10 ..) and its clear these can never be palindromic
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        // this will hold the reverted number to compare with
        int revertedNo = 0;

        // till 'x' is greater than reverted number, iterate through (here greater in terms of digits will be greater number)
        // 'x' will reduce by 1 digit every iteration and 'revertedNo' will increase 1 digit
        // it will loop for (n/2 +1) times where 'n' is initial length of 'x'
        while (x > revertedNo)
        {
            // std::cout << "x : " << x << "   revertedNo : " << revertedNo << std::endl;

            // pushing the next digit of 'x' in 'revertedNo' form back to generate reverted number
            revertedNo = ((revertedNo * 10) + (x % 10));
            // reducing the x 1 digit form rear side
            x /= 10;
        }
        // return true if the reverted number is eaual to given number
        // or given number is of one digit
        return (revertedNo == x || revertedNo / 10 == x);
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    std::cout << s.isPalindrome(313) << std::endl;

    return 0;
}