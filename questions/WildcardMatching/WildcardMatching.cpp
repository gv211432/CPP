// Main file of the Project
#include <bits/stdc++.h>
#include "../utilities/utilities.h"
using namespace std;

// class Solution
// {
// public:
//     bool isMatch(const string s, const string p)
//     {
//         const int dp_size = p.size();
//         const int dp0_size = s.size();

//         // bool dp[dp_size + 1][dp0_size + 1] = {{0}};

//         bool *dp = new bool[dp_size * dp0_size];
//         // bool hi = (bool *)malloc(dp_size * dp0_size * sizeof(bool));
//         // memset(dp, 0, dp_size * dp0_size * sizeof(bool));
//         // std::cout << dp_size << std::endl;
//         // std::cout << dp0_size << std::endl;

//         for (int i = dp_size; i >= 0; i--)
//         {
//             // std::cout << "i :" << i << std::endl;
//             for (int j = dp0_size; j >= 0; j--)
//             {
//                 // std::cout << "j : " << j << std::endl;
//                 if (i == dp_size && j == dp0_size)
//                 {
//                     *(dp + i * dp0_size + j) = true;
//                 }
//                 else if (i == dp_size)
//                 {
//                     *(dp + i * dp0_size + j) = false;
//                 }
//                 else if (j == dp0_size)
//                 {
//                     if (p[i] == '*')
//                         *(dp + i * dp0_size + j) = *(dp + i * dp0_size + 1 + j);
//                     else
//                         *(dp + i * dp0_size + j) = false;
//                 }
//                 else
//                 {
//                     if (p[i] == '?')
//                         *(dp + i * dp0_size + j) = *(dp + (i + 1) * dp0_size + (j + 1));
//                     else if (p[i] == '*')
//                         *(dp + i * dp0_size + j) = *(dp + (i + 1) * dp0_size + j) || *(dp + i * dp0_size + (j + 1));
//                     else if (p[i] == s[j])
//                         *(dp + i * dp0_size + j) = *(dp + (i + 1) * dp0_size + (j + 1));
//                     else
//                         *(dp + i * dp0_size + j) = false;
//                 }
//             }
//         }
//         return *dp;
//     }
// };

//                  Arrow showing reference
//         b     a     a     a     b    a     b     null
//       ┌──────────────────────────────────────────────┐
//       |    |     |     |     |     |     |     |     |
//    b  | 1➘ |  0  |  0  |  0  | 0➘  |  0  | 0➘  |  0  |
//       |    |     |     |     |     |     |     |     |
//       +──────────────────────────────────────────────+
//       |    |     |     |     |     |     |     |     |
//    a  | 0  |  1➘ | 1➘  | 1➘  |  0  | 0➘  |  0  |  0  |
//       |    |     |     |     |     |     |     |     |
//       +──────────────────────────────────────────────+
//       |    |     |     |     |     |     |     |     |
//    *  |1↓➘↷| 1↓➘↷| 1↓➘↷| 1↓➘↷| 1↓➘↷|1↓➘↷ |0↓➘↷ |  0↓ |
//       |    |     |     |     |     |     |     |     |
//       +──────────────────────────────────────────────+
//       |    |     |     |     |     |     |     |     |
//    a  | 0➘ | 0➘  | 0➘  | 0➘  |  0  | 1➘  |  0  |  0  |
//       |    |     |     |     |     |     |     |     |
//       +──────────────────────────────────────────────+
//       |    |     |     |     |     |     |     |     |
//    ?  | 0➘ | 0➘  | 0➘  | 0➘  |  0➘ | 0➘  | 1➘  |  0  |
//       |    |     |     |     |     |     |     |     |
//       +──────────────────────────────────────────────+
//       |    |     |     |     |     |     |     |     |
// null  |  0 |  0  |  0  |  0  |  0  |  0  |  0  |  1  |
//       |    |     |     |     |     |     |     |     |
//       └──────────────────────────────────────────────┘
//  if single character or ? matches with each other, take reference from right-bottom(diagonal) element
//  if * then take reference from the bottom and all elements on bottom-right

class Solution
{
public:
    bool isMatch(const string s, const string p)
    {
        const int dp_size = p.size();
        const int dp0_size = s.size();

        // bool dp[dp_size + 1][dp0_size + 1] = {};
        // std::cout << dp_size << std::endl;
        // std::cout << dp0_size << std::endl;
        vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, 0));

        for (int i = dp_size; i >= 0; i--)
        {
            // std::cout << "i :" << i << std::endl;
            for (int j = dp0_size; j >= 0; j--)
            {
                // std::cout << "j : " << j << std::endl;
                if (i == dp_size && j == dp0_size) // null matches with null
                {
                    dp[i][j] = true;
                }
                else if (i == dp_size) // null does not matches with characters
                {
                    dp[i][j] = false;
                }
                else if (j == dp0_size)
                {
                    if (p[i] == '*') // null can match with *, hence it result depends on below match
                        dp[i][j] = dp[i + 1][j];
                    else // null does not match with characters
                        dp[i][j] = false;
                }
                else
                {
                    if (p[i] == '?') // any, one character will match with ?, hence its result depends on diagonal match
                        dp[i][j] = dp[i + 1][j + 1];
                    else if (p[i] == '*') // every thing will match with *, hence its result depends on below match and all matches right to below
                        dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
                    else if (p[i] == s[j]) // if character match with each other, there result depends on diagonal match
                        dp[i][j] = dp[i + 1][j + 1];
                    else // no match
                        dp[i][j] = false;
                }
            }
        }

        boxes::Box.Box_2(dp, p, s);
        boxes::Box.Box_1(dp, p, s);
        return dp[0][0];
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    // std::cout << s.isMatch("oeuropu", "o*pu")
    //           << std::endl;
    std::cout << s.isMatch("aacabdkacaaplyuaac", "aa*a?")
              << std::endl;
    return 0;
}