// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;

        map<int, int> m;

        // putting the elements in a map for faster lookup O(log n)
        for (size_t i = 0; i < nums.size(); i++)
        {
            // making nums[i] as key and it's index as value
            m.insert(make_pair(nums[i], i));
        }

        // if the complement key exist in the map, you will find the answer
        for (size_t i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if (m.find(complement) != m.end() && m.find(complement)->second != i)
            {
                v.clear();
                v.push_back(i);                          // i is the current index of the nums[]
                v.push_back(m.find(complement)->second); // retrieve the index of complement form th map
                break;
            }
        }

        // std::cout << "[ " << *(v.begin()) << ", " << *(v.begin() + 1) << " ]" << std::endl;

        return v;
    }
};

int main(int arg, char *argv[])
{
    std::vector<int> nums = {-1, -2, -3, -4, -5};
    int target = -8;
    Solution s;
    s.twoSum(nums, target);
    return 0;
}