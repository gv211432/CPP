// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        // Time O(N) and Space O(N)
        // vector<int> dp(s.size() + 1, 1);
        // for (int i = s.size() - 1; i >= 0; i--)
        // {
        //     (s[i] == '0') ? dp[i] = 0 : dp[i] = dp[i + 1];
        //     if (i + 1 < s.size() and (s[i] == '1' or (s[i] == '2' and s[i + 1] >= '0' and s[i + 1] <= '6')))
        //         dp[i] += dp[i + 2];
        // std::cout << "dp[i] : " << dp[i] << std::endl;
        // }
        // return dp[0];

        // Time O(N) and Space O(1)
        int a = 0, b = 1, c = 1;                // declare three variable which keeps the no. of ways of last three characters of given string respectively
        for (int i = s.size() - 1; i >= 0; i--) // traversing the string form backword
        {
            (s[i] == '0') ? a = 0 : a = b; // if character in 0, make a = 0 else put the next character's ways value in it
            // if "i" is not last character and if "i" is 1 or if "i" is 2 and RHS value is less than 6 add "c" to "a"(last value to first value)
            if (i + 1 < s.size() and (s[i] == '1' or (s[i] == '2' and s[i + 1] >= '0' and s[i + 1] <= '6')))
                a += c;
            c = b, b = a; // than transfer values b -> c, a -> b
            // std::cout << "a : " << a << " b: " << b << " c: " << c << std::endl;
        }
        return a;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    std::cout << s.numDecodings("226") << std::endl;
    std::cout << s.numDecodings("22") << std::endl;
    std::cout << s.numDecodings("1") << std::endl;
    return 0;
}