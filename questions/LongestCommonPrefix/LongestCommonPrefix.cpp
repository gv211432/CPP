// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

// debug acceped both solutions by leetcode

class Solution // just useless
{
public:
    string longestCommonPrefix(vector<string> &strs) // O(n^2)
    {
        // finding the smallest string in the given vector "strs" with its index
        size_t stringIndex, stringLen = INT_MAX;

        // index counter for the following loop
        int i = 0;
        for (auto s : strs) // O(n)
        {
            if (s.size() < stringLen)
                (stringIndex = i, stringLen = s.size());
            i++;
        }

        std::cout << "String index is : " << stringIndex << " and length is : " << stringLen << std::endl;
        string ans = "";
        for (size_t j = 0; j < stringLen; j++) // O(n)
        {
            for (auto s : strs) // O(n)
            {
                // std::cout << s << std::endl;
                if (!(((strs[stringIndex])[j] == s[j])))
                    return ans;
            }
            ans += (strs[stringIndex])[j];
        }
        return ans;
    }
};

class Solution2
{
public:
    string longestCommonPrefix(vector<string> &strs) // O(n)
    {
        // "len" contains the size of the given vector
        int len = strs.size();
        // let "ans" be the first string of the given vector
        string ans = strs[0];
        // iterating for the remaining string in the given vector
        for (int i = 1; i < strs.size(); i++) // O(n)
        {
            // iterate for the no. of times equals to the current string size take is a O(1)

            // For the very first iteration it cross matches the first string with the second one
            // and loads the matching substring in "ans" and try to match the "ans" in all string
            // if doesn't match it reduces the length by one and try again untill matched..
            while (strs[i].find(ans) != 0)
                ans = ans.substr(0, ans.length() - 1);
        }

        // return the "ans" string
        return ans;
    }
};

int main(int arg, char *argv[])
{
    Solution2 s;
    vector<string> str = {"flower", "flow", "flight"};

    // std::cout << str[1].find("flower") << std::endl;

    std::cout << s.longestCommonPrefix(str) << std::endl;

    return 0;
}