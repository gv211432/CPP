// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // Soulution1: Linear search
        // for (size_t i = 0; i < nums.size(); i++)
        //     if (nums[i] >= target)
        //         return i;
        // return nums.size();

        // Solution2: Binary search
        // Binary search for finding target index or expected index if target is not present
        int l = 0, mid = 0, r = nums.size() - 1;

        // loop till l goes greater than rs
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else
                (nums[mid] < target) ? l = mid + 1 : r = mid - 1;
        }
        // if target is not present
        // if target is less than found index, return the same index
        // if target is greater than found index, return index +1
        return (target < nums[mid]) ? mid : mid + 1;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    vector<int> v = {1, 3, 5, 6};
    int t = 0;
    std::cout << s.searchInsert(v, t) << std::endl;
    return 0;
}