// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // this is expand around center algorithm
    int ExpandAroundCenter(string s, int left, int right)
    {
        // delclare two number variables for iteration
        int L = left, R = right;
        // iterate till conditions is met
        while ((L >= 0) && (R < s.length()) && (s[L] == s[R]))
            L--, R++;
        return (R - L - 1);
    };

public:
    string longestPalindrome(string s)
    {
        // if given string is empty return empty stiring
        if (s.empty())
            return "";

        // declaring start and end index for further use
        int start = 0, end = 0;

        // loop the whole string for every character
        for (int i = 0; i < s.length(); i++)
        {
            int len1 = ExpandAroundCenter(s, i, i), len2 = ExpandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);

            if (len > end - start)
                start = (i - ((len - 1) / 2)), end = (i + (len / 2));
        }
        return s.substr(start, (end - start) + 1);
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    std::cout << s.longestPalindrome("lkjhduyteanbabababababba") << std::endl;
    return 0;
}