// Main file of the Project
// #include "../utilities/utilities.h"
#include <bits/stdc++.h>
using namespace std;

void PrintVec(vector<char> &v)
{
    std::cout << "[ ";
    for (auto e : v)
        std::cout << to_string(e + 'a') << ", ";
    std::cout << "]" << std::endl;
}

// working but slow
class Solution2
{
    string permute(string s)
    {
        if (s.size() <= 1)
            return s;

        string end = s.substr(1, s.size());

        s = end + s[0];

        return "";
    }

public:
    string getPermutation(int n, int k)
    {
        string s = "";
        vector<char> v(n, '0');
        vector<vector<char>> ans;

        while (n--)
            v[n] = n - 96;

        // PrintVec(v);
        ans.push_back(v);
        while (--k)
            next_permutation(v.begin(), v.end()),
                ans.push_back(v);

        for (auto c : ans[ans.size() - 1])
            s += to_string(c + 'a');

        // std::cout << "Last ans : " << s << std::endl;
        return s;
    }
};

class Solution
{
public:
    string getPermutation(int n, int k) // Time O(N)
    {
        k--;                               // this code is based on 0 based indexing, hence reducing k by 1
        vector<int> nums(n, 0);            // declaring vector to store candidate numbers
        int fact = 1, no = n, p_index = 0; // "fact" to store the current factorial, "no" copy of "n",
                                           // "p_index" to store the current index of number in "nums"

        while (--n)                     // loop till "n" becomes 0, here generating factorial of "n" and
            fact *= n, nums[n] = n + 1; // putting candidate numbers in "nums", eg : [2,3,4]
        nums[0] = 1;                    // eg : [1,2,3,4]

        string ans = ""; // this will hold the answer string
        while (no--)     // use "no" for looping dicision and decrement
        {
            p_index = (k / fact);                // index of number in "nums"
            ans += to_string(nums[p_index]);     // copy the number at "p_index" in "ans" string
            nums.erase(nums.begin() + p_index);  // erase this number after copying in "ans"
            k = k % fact;                        // updating "k" with remainder of "k"/"fact"
            fact = no == 0 ? fact : fact / (no); // when "no" becomes 0, handle it, update fact
        }
        return ans; // returning the ans
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    // s.getPermutation(4, 9);
    cout << s.getPermutation(4, 17);
    return 0;
}