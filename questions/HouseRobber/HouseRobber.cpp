// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // ❎ Not working
        // vector<int> dp(nums.size() + 1, 0);
        // int temp = 0;
        // for (int i = nums.size() - 1; i >= 0; i--)
        // {
        //     temp = max(nums[i], nums[i + 1]);
        //     dp[i] += temp;
        // }
        // return dp[0];

        // ✅ it is working
        // Time O(N), Space O(1)
        int rob1 = 0, rob2 = 0;
        for (auto n : nums)
        {
            int temp = max(n + rob1, rob2);
            rob1 = rob2, rob2 = temp;
        }
        return rob2;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    vector<int> v = {1, 2, 3, 1};
    std::cout << s.rob(v) << std::endl;
    return 0;
}