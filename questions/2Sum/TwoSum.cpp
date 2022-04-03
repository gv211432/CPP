// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

// utility function
void PrintVoV(vector<vector<int>> v)
{
    for (auto x : v)
    {
        std::cout << "[ ";
        for (auto n : x)
        {
            std::cout << n;
            n == x.back() ? cout << " " : cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

// first solution of the problem
class Solution
{
public:
    // returns the index of the required solution
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;

        unordered_map<int, size_t> m; // O()

        // putting the elements in a map for faster lookup O(log n)
        for (size_t i = 0; i < nums.size(); i++)
            m.insert(make_pair(nums[i], i)); // making nums[i] as key and it's index as value

        // if the complement key exist in the map, you will find the answer
        for (size_t i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i]; // laoding the difference of the target and the nums elements

            // if map is not empty and complement exist in the map
            if (m.find(complement) != m.end() && m.find(complement)->second != i)
            {
                v.clear(), v.push_back(i);               // i is the current index of the nums[]
                v.push_back(m.find(complement)->second); // retrieve the index of complement form th map
                break;
            }
        }

        std::cout << "[ " << *(v.begin()) << ", " << *(v.begin() + 1) << " ]" << std::endl;
        return v;
    }
};

// second solution
class Solution2
{
public:
    // return the vector of vector containing the value of the solutions
    vector<vector<int>> twoSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res; // creating a VoV for string and returning the answer
        unordered_set<int> s;    // this will store the numbers for "nums" for faster lookup (eg: to get count)

        for (size_t i = 0; i < nums.size(); ++i)
        {
            // if "res" is empty or "res" last vector's second element is not equal to current "nums" element (prevents duplication)
            // and if there exist any element equals to the difference of "target" and "nums" current element
            if ((res.empty() || res.back()[1] != nums[i]) && s.count(target - nums[i])) // θ(1),O(n)
                res.push_back({target - nums[i], nums[i]});
            s.insert(nums[i]);
        }

        return res;
    }
};

int main(int arg, char *argv[])
{
    std::vector<int> nums = {-1, -2, -3, -4, -5};
    int target = -8;
    Solution s1;
    s1.twoSum(nums, target);
    Solution2 s2;
    PrintVoV(s2.twoSum(nums, target));
    return 0;
}