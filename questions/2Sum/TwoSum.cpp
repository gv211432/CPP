// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

// utility function for printing Vector of Vector
void PrintVoV(vector<vector<int>> v)
{
    for (auto x : v)
    {
        std::cout << "{ ";
        for (auto &n : x)
            std::cout << n, &n == &x.back() ? cout << " " : cout << ", ";
        std::cout << "}" << std::endl;
    }
}

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        unordered_map<int, int> m; // to store the given numbers for faster lookup ie. O(N)
        // if the complement key exist in the map, you will find the answer
        for (size_t i = 0; i < nums.size(); i++)
        {
            // loading the difference of the target and the nums elements in complement
            int complement = target - nums[i];

            std::cout << "i : " << i << " complement : " << complement << std::endl;
            if (m.find(complement) != m.end()) // if complement is present in "m"
            {
                ans.push_back(i);             // i is the current index of the nums[]
                ans.push_back(m[complement]); // retrieve the index of complement form th map
                return ans;                   // if one solution is found we are done
            }
            m.emplace(make_pair(nums[i], i)); // putting the elements in a map for faster lookup O(N)
        }
        // std::cout << "[ " << *(v.begin()) << ", " << *(v.begin() + 1) << " ]" << std::endl;
        return ans;
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
    std::vector<int> nums = {3, 2, 4};
    int target = 6;
    Solution s1;
    s1.twoSum(nums, target);
    Solution2 s2;
    PrintVoV(s2.twoSum(nums, target));
    return 0;
}