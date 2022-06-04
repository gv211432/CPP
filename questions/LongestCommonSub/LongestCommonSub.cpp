// Main file of the Project
#include <bits/stdc++.h>
#include "../utilities/utilities.h"
using namespace std;

class Solution
{
public:
    // this returns size of longest common subsequence
    int longestCommonSubsequence(string &text1, string &text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int r = text1.size() - 1; r >= 0; r--)
            for (int c = text2.size() - 1; c >= 0; c--)
                if (text1[r] == text2[c])
                    dp[r][c] = 1 + dp[r + 1][c + 1];
                else
                    dp[r][c] = max(dp[r + 1][c], dp[r][c + 1]);

        // std::cout << text1 << std::endl;
        return dp[0][0];
    }

    // this retuns the longest common subsequence itself
    string lcs(string &text1, string &text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        vector<vector<int>> trace(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int r = text1.size() - 1; r >= 0; r--)
            for (int c = text2.size() - 1; c >= 0; c--)
                if (text1[r] == text2[c])
                    dp[r][c] = 1 + dp[r + 1][c + 1];
                else
                    dp[r][c] = max(dp[r + 1][c], dp[r][c + 1]);

        string ans = "";
        int i = 0, j = 0;
        while (dp[i][j] > 0)
        {
            if (dp[i][j] == dp[i + 1][j])
                // cout << "down\n",
                i++, ans = "", trace[i - 1][j] = 1;
            else if (dp[i][j] == dp[i][j + 1])
                // cout << "right\n",
                j++, ans = "", trace[i][j - 1] = 1;
            else if (dp[i][j] == dp[i + 1][j + 1] + 1)
            {
                // cout << "Diagonal : " << text1[i] << "\n";
                trace[i][j] = 1;
                ans += text1[i];
                i++, j++;
            }
            // std::cout << "i : " << i << " j: " << j << std::endl;
        }
        std::cout << ans << std::endl;

        boxes::Box.Box_1(dp, "acbd", "ytrd", trace);
        boxes::Box.Box_1(dp, "acbd", "ytrd", dp);
        // boxes::Box.Box_2(trace, "", "", {});
        // boxes::Box.Box_2(trace, "", text2, {});
        // boxes::Box.Box_2(trace, "acbd", ""ytrd"", {});
        // boxes::Box.Box_2(trace, text1, text2, trace);
        return ans;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    string t1 = "aacabdkacaaplyutre";
    string t2 = t1;
    reverse(t2.begin(), t2.end());
    s.lcs(t1, t2);
    // std::cout << s.longestCommonSubsequence(t1, t2) << std::endl;
    // string t2 = "aaca";
    // std::cout << s.longestCommonSubsequence(t1, t2) << std::endl;

    vector<vector<int>> v0 = {{0}};
    vector<vector<int>> v1 = {{9}, {8}, {8}, {68}};
    vector<vector<int>> v2 = {{9, 5, 9}};
    vector<vector<int>> v3 = {
        {9, 5, 9},
        {9, 5, 9},
        {9, 5, 9},
    };
    // boxes::Box.Box_1(v0, "a", "a", {});
    // boxes::Box.Box_1(v1, "abc", "a", {});
    // boxes::Box.Box_1(v2, "abc", "a", {});
    // boxes::Box.Box_1(v3, " ", " ", {});
    boxes::Box.Box_1(v3);
    return 0;
}
//       a     a     c     a     k     d     b     a     c     a     a
//    ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
// a  ┃  9  ┃  8  ┃  7  ┃  6  ┃  5  ┃  5  ┃  5  ┃  4  ┃  3  ┃  2  ┃  1  ┃  0  ┃
//    ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
// a  ┃  8  ┃  8  ┃  7  ┃  6  ┃  5  ┃  5  ┃  5  ┃  4  ┃  3  ┃  2  ┃  1  ┃  0  ┃
//    ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
// c  ┃  7  ┃  7  ┃  7  ┃  6  ┃  5  ┃  5  ┃  5  ┃  4  ┃  3  ┃  2  ┃  1  ┃  0  ┃
//    ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
// a  ┃  6  ┃  6  ┃  6  ┃  6  ┃  5  ┃  5  ┃  5  ┃  4  ┃  3  ┃  2  ┃  1  ┃  0  ┃
//    ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
// b  ┃  5  ┃  5  ┃  5  ┃  5  ┃  5  ┃  5  ┃  5  ┃  4  ┃  3  ┃  2  ┃  1  ┃  0  ┃
//    ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
// d  ┃  5  ┃  5  ┃  5  ┃  5  ┃  5  ┃  5  ┃  4  ┃  4  ┃  3  ┃  2  ┃  1  ┃  0  ┃
//    ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
// k  ┃  5  ┃  5  ┃  5  ┃  5  ┃  5  ┃  4  ┃  4  ┃  4  ┃  3  ┃  2  ┃  1  ┃  0  ┃
//    ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
// a  ┃  4  ┃  4  ┃  4  ┃  4  ┃  4  ┃  4  ┃  4  ┃  4  ┃  3  ┃  2  ┃  1  ┃  0  ┃
//    ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
// c  ┃  3  ┃  3  ┃  3  ┃  3  ┃  3  ┃  3  ┃  3  ┃  3  ┃  3  ┃  2  ┃  1  ┃  0  ┃
//    ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
// a  ┃  2  ┃  2  ┃  2  ┃  2  ┃  2  ┃  2  ┃  2  ┃  2  ┃  2  ┃  2  ┃  1  ┃  0  ┃
//    ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
// a  ┃  1  ┃  1  ┃  1  ┃  1  ┃  1  ┃  1  ┃  1  ┃  1  ┃  1  ┃  1  ┃  1  ┃  0  ┃
//    ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
//    ┃  0  ┃  0  ┃  0  ┃  0  ┃  0  ┃  0  ┃  0  ┃  0  ┃  0  ┃  0  ┃  0  ┃  0  ┃
//    ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛