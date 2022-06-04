// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) // if row is 1 just return the string
            return s;

        string ret = "";                 // answer string
        int n = s.size();                // length of the given string
        int cycle_len = 2 * numRows - 2; // to increment

        for (int i = 0; i < numRows; i++) // traverse through rows
        {
            for (int j = 0; j + i < n; j += cycle_len) // increment by the cycle_len
            {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycle_len - i < n)
                    ret += s[j + cycle_len - i];
            }
        }
        return ret;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    std::cout << s.convert("PAYPALISHIRING", 3) << std::endl;
    return 0;
}