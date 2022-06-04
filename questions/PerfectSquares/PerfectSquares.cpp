// Main file of the Project
#include <bits/stdc++.h>
#include "../utilities/utilities.h"
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        // slef made, not working ❎
        // vector<int> dp(n + 1, 1);
        // for (int i = 1; i <= n; i++)
        // {
        //     if (ceil(sqrt(i)) == floor(sqrt(i)))
        //         continue;
        //     dp[i] = i; // max value for any number is number itself
        //     for (int j = 1; j < i; j++)
        //         dp[i] = min(dp[j] + dp[i - j], dp[i]);
        // }
        // return dp[n];

        // working fine ✅
        vector<int> dp(n + 1, n); // slower
        // int dp[n + 1] = {}; // faster
        dp[0] = 0;
        // for (int i = 1; i <= n; i++)
        //     dp[i] = n;

        int i = 1, j = 1;
        // traversing the array and filling the minimum number of perfect
        // squares required for every numbers befor the final result
        for (i = 1; i <= n; i++)
            for (j = 1; j < i + 1; j++)
            {
                int square = j * j;
                if (i - square < 0)
                    break;
                dp[i] = min(dp[i], 1 + dp[i - square]);
                // std::cout << "i : " << i << ", j : " << j << ", dp[i]: " << dp[i] << std::endl;
            }
        boxes::Box.Box_2(dp);
        return dp[n];
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    std::cout << s.numSquares(12) << std::endl;
    std::cout << s.numSquares(13) << std::endl;
    return 0;
}