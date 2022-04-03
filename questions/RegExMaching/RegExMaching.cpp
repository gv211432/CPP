// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    bool isMatch(string s, string p)
    {

        // creating a datapointer(Table) to store a data of previously matched string
        bool dp[s.size()][p.size()] = {};

        // first value have to be true for algo to work
        dp[0][0] = 1;

        for (int i = 0; i <= s.size(); i++)
        {
            // filling table form top to bottom
            for (int j = 1; j <= p.size(); j++)
            {
                // filling the table form left to right on some conditions
                // here first row and column have to be false

                // if p[j-1] == '*'
                // first check if dp[i][j-2] == 1, put dp[i][j]=1 or
                // s[i]==p[j-1] or p[j-1]=='.' then=> check if dp[i-1][j]==1 then put dp[i][j]=1

                // if s[i]==p[i] or p[i]=='.' then put dp[i][j]=dp[i-1][j-1]

                // other wise 0 every where....
                if (p[j - 1] == '*')
                    dp[i][j] = (i && (dp[i - 1][j - 1] || dp[i - 1][j]) && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) || dp[i][j - 1] || dp[i][j - 2];
                else
                    dp[i][j] = (i && dp[i - 1][j - 1]) && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
        // // For debugging purpose
        // for (int i = 0; i <= s.size(); i++)
        // {
        //     for (int j = 0; j <= p.size(); j++)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        return dp[s.size()][p.size()];
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    std::cout << "Truth value of \"aa\" and \"a\" :  " << s.isMatch("aa", "a") << std::endl;
    std::cout << "Truth value of \"aa\" and \"a*\" :  " << s.isMatch("aa", "a*") << std::endl;
    return 0;
}