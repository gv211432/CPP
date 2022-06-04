// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int r, int &n, set<int> &col, set<int> &posDiag, set<int> &negDiag, vector<vector<string>> &board, vector<vector<string>> &res)
    {
        if (r == n)
        {
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        set<int> col = {};
        set<int> posDiagonal = {}; // r+c
        set<int> negDiagonal = {}; // r-c
        vector<vector<string>> res = {};
        vector<vector<string>> board(n, vector<string>(n, "."));
    }
};

int main(int arg, char *argv[])
{
    Solution s;

    return 0;
}