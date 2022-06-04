// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int firstMissingPositive(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end()); // sorting the given vector
//         int m = 1;                      // smallest postive number
//         for (auto n : nums)
//             if (n == m) // if smallest postive number is present in vector, increment by 1
//                 m++;
//         return m;
//     }
// };

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        for (size_t i = 0; i < nums.size(); i++)
            if (nums[i] < 0)
                nums[i] = 0;

        for (auto n : nums)
        {
            size_t val = abs(n);
            if (val >= 1 and val <= nums.size())
            {
                if (nums[val - 1] > 0)
                    nums[val - 1] *= -1;
                else if (nums[val - 1] == 0)
                    nums[val - 1] = -1 * (nums.size() + 1);
            }
        }
        // solution set = [1, nums.size() + 1]
        for (size_t i = 1; i < nums.size() + 1; i++)
            if (nums[i - 1] >= 0)
                return i;

        return nums.size() + 1; // worst case if solution not found in the hashset
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    vector<int> n1 = {7, 8, 9, 11, 12};
    vector<int> n2 = {1, 2, 0};
    vector<int> n3 = {3, 4, -1, 1};
    vector<int> n4 = {-5};
    std::cout << s.firstMissingPositive(n1) << std::endl;
    std::cout << s.firstMissingPositive(n2) << std::endl;
    std::cout << s.firstMissingPositive(n3) << std::endl;
    std::cout << s.firstMissingPositive(n4) << std::endl;
    return 0;
}