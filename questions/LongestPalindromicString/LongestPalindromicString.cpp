// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

// Expand around center O(N^2)
class Solution
{
    // this is expand around center algorithm
    int ExpandAroundCenter(string s, int left, int right)
    {
        // delclare two number variables for iteration
        int L = left, R = right;
        // iterate till conditions is met
        // while left and right dosen't cross their boundries and they are equal
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

        // declaring start and end index pointer
        int start = 0, end = 0;

        // traverse the string once
        for (int i = 0; i < s.length(); i++)
        {
            // for handling even and odd case, we do this max comparision
            int len1 = ExpandAroundCenter(s, i, i),     // Odd case: abcdcba
                len2 = ExpandAroundCenter(s, i, i + 1), // Even case: abccba
                len = max(len1, len2);                  // bigger length will be palindrome's length

            if (len > end - start) // if curren palindrome is bigger than previous one, update the  start and end index
                start = (i - ((len - 1) / 2)), end = (i + (len / 2));
        }
        return s.substr(start, (end - start) + 1);
    }
};

// Manachers algorithm insight O(N)
// 1. Don't make any index center, when it is totally contained under current palindrome
// 2. Break out of the loop, when the current palindrome expands till end of given input
// 3. Pick character as a center when it expand till right edge of curren palindrome and its mirror palindrome is prefix
// 4. Don't pick character as new center if it expand till right edge and its mirror palindrome expands beyond left edge

// Longest palindromic string (lps) solution
class Solution2
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";

        vector<int> L(2 * s.size() + 1, 0);
        L[1] = 1;
        int C = 0,    // center position
            R = 1,    // center right position
            i = 0,    // current right position
            i_mirror, // current left position
            max_lps_length = 0,
            max_lps_center_length = 0,
            start = 1,
            end = -1,
            diff = -1;

        for (size_t i = 2; i < L.size(); i++)
        {
            i_mirror = 2 * C - i;
            diff = R - i;
            if (diff > 0)
                L[i] = max(L[i_mirror], diff);

            while (((i + L[i]) < L.size() && (i - L[i]) > 0) &&
                   (((i + L[i] + 1) % 2 == 0) ||
                    (s[(i + L[i] + 1) / 2] == s[(i - L[i] - 1) / 2])))
                L[i]++;

            if (L[i] > max_lps_length)
                max_lps_length = L[i], max_lps_center_length = i;

            if ((i + L[i]) > R)
                C = i, R = i + L[i];
        }

        start = (max_lps_center_length - max_lps_length) / 2;
        end = max_lps_length + start;

        // std::cout << s.substr(start, end) << std::endl;
        return s.substr(start, (end - start));
    }
};

int main(int arg, char *argv[])
{
    Solution s;

    Solution2 s2;

    std::cout << s.longestPalindrome("babad") << std::endl;
    std::cout << s2.longestPalindrome("babad") << std::endl;

    std::cout << s.longestPalindrome("aacabdkacaa") << std::endl;
    std::cout << s2.longestPalindrome("aacabdkacaa") << std::endl;

    return 0;
}