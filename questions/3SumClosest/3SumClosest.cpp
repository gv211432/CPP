// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

#define NOOP() (1)
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());          // sorting the given array
        int diff = INT_MAX;                      // creating a diff variable to store difference
        for (size_t i = 0; i < nums.size(); i++) // iterate the given vector for once O(n)O(n) = O(n^2)
        {
            int start = i + 1, end = nums.size() - 1; // two pointers for two-pointer technique O(n)
            while (start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];                      // finding the sum of current pointed numbers
                (abs(sum - target) < abs(diff)) ? (diff = target - sum) : NOOP(); // if absolute of difference of sum and target
                (sum < target) ? start++ : end--;                                 // is sum is less than target increment start pointer to bring closer to 0 and vice-versa
            }
        }
        return target - diff;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    // vector<int> v = {0, 0, 0};
    vector<int> v = {-1, 2, 1, -4};
    std::cout << s.threeSumClosest(v, 1) << std::endl;
    return 0;
}