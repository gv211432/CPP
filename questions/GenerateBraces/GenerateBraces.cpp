// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // vector<string> generateParenthesis(int n)
    // {
    //     vector<string> s;
    //     if (n == 1)
    //     {
    //         s.push_back("()");
    //         return s;
    //     }
    //     else
    //     {
    //         auto r = generateParenthesis(n - 1);
    //         s.push_back("()" + *r.begin());
    //         s.push_back("(" + *r.begin() + ")");
    //         return s;
    //     }
    // }

    vector<string> generateParenthesis(int n)
    {
        vector<string> s;
        if (n == 0)
            s.push_back("");
        else
        {
            for (int c = 0; c < n; ++c)
                for (auto left : generateParenthesis(c))
                    for (auto right : generateParenthesis(n - 1 - c))
                        s.push_back("(" + left + ")" + right);
        }
        return s;
    }
};

void PrintBraces(vector<string> s)
{
    std::cout << "[ ";
    for (auto x : s)
    {
        std::cout << x << ", ";
    }
    std::cout << "]" << std::endl;
}

int main(int arg, char *argv[])
{
    Solution s;
    PrintBraces(s.generateParenthesis(3));
    return 0;
}