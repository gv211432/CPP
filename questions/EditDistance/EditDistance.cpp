// Main file of the Project
#include <bits/stdc++.h>
#include "../utilities/utilities.h"
using namespace std;

class Solution
{
public:
    int minDistance(string text1, string text2)
    {
        // this dp will hold all the possible operations
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        // generating all possible operations (bottom up approach)
        for (int i = text1.size(); i >= 0; i--)     // traversing outer vector
            for (int j = text2.size(); j >= 0; j--) // traversing inner vector
                if (j == text2.size())              // for empty char it will definetly take number of operations equals to size of string
                    dp[i][j] = text1.size() - i;    // incrementing one by one for each characters
                else if (i == text1.size())         // for empty char it will definetly take number of operations equals to size of string
                    dp[i][j] = text2.size() - j;
                else if (text1[i] == text2[j])                          // if characters are matching, we need not to do anything
                    dp[i][j] = dp[i + 1][j + 1];                        // result will depend on dp[i+1][j+1]
                else                                                    // but if not matching it will take on more operation (delete or insert)
                    dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]),         //  + pending previous operations to make strings equal, hence
                        dp[i][j] = min(dp[i + 1][j + 1], dp[i][j]) + 1; // taking minimum of all three options and adding 1
        // boxes::Box.Box_2(dp, text1, text2, {}); // debugging purpose
        return dp[0][0]; // return the first value, it hold the least number of operations required
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    s.minDistance("abd", "acd");
    return 0;
}