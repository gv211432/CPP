// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool is_valid(string s)
    {
        size_t st = 0;
        for (int i = 0; s[i]; i++)
            if (s[i] == '(')
                st++;
            else if (!st)
                st--;
        return st ? true : false;
    }

public:
    int longestValidParentheses(string s)
    {
        int max_len = 0;
        vector<int> dp = {};

        for (int i = 0; s[i]; i++)
            dp.push_back(0);

        for (size_t i = 1; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                max_len = max(max_len, dp[i]);
            }
        }
        return max_len;
    }
};

int main(int arg, char *argv[])
{
    string str1 = ")()())";
    string str2 = "()(()";
    string str3 = "(()";

    Solution s;

    std::cout << s.longestValidParentheses(str1) << std::endl;
    std::cout << s.longestValidParentheses(str2) << std::endl;
    std::cout << s.longestValidParentheses(str3) << std::endl;
    std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}