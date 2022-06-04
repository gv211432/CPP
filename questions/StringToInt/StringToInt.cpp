// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int reNo = 0;
        bool doesNeg = false;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '-')
                doesNeg = true;

            // std::cout << (s[i] - '0') << std::endl;

            if ((s[i] - '0') >= 0 && (s[i] - '0') <= 9)
            {
                if ((reNo > INT_MAX / 10) && ((reNo > INT_MAX / 10) && (s[i] - '0') > 7))
                    return 0;
                if ((reNo > INT_MAX / 10) && ((reNo > INT_MAX / 10) && (s[i] - '0') < -8))
                    return 0;
                reNo = (reNo * 10) + (s[i] - '0');
            }
        }

        return doesNeg ? (-1) * reNo : reNo;
    }
};

class Solution2 // O(n)
{
public:
    int myAtoi(string input)
    {
        int sign = 1;
        int result = 0;
        int index = 0;
        int n = input.size();

        // Discard all spaces from the beginning of the input string.
        while (index < n && input[index] == ' ')
            index++;

        // sign = +1, if it's positive number, otherwise sign = -1.
        if (index < n && input[index] == '+')
            sign = 1, index++;
        else if (index < n && input[index] == '-')
            sign = -1, index++;

        // Traverse next digits of input and stop if it is not a digit.
        // End of string is also non-digit character.
        while (index < n && isdigit(input[index]))
        {
            int digit = input[index] - '0'; // convertig for ascii to int
            // Check overflow and underflow conditions.
            if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) // NOTE it
                // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.
                return sign == 1 ? INT_MAX : INT_MIN;

            // Append current digit to the result.
            result = 10 * result + digit;
            index++;
        }

        // We have formed a valid number without any overflow/underflow.
        // Return it after multiplying it with its sign.
        return sign * result;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    std::cout << s.myAtoi("4193 with words") << std::endl;

    std::cout << s.myAtoi("words and 987") << std::endl;

    std::cout << s.myAtoi("    -42") << std::endl;

    // std::cout << ('9' - '0') << std::endl;

    return 0;
}