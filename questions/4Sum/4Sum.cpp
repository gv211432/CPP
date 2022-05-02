// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k)
    {
        vector<vector<int>> res; // declaring "res" to store the solution vectors

        // If we have run out of numbers to add, return "res".
        if (start == nums.size())
            return res;

        // There are k remaining values to add to the sum. The
        // average of these values is at least target / k.
        int average_value = target / k;

        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if (nums[start] > average_value || average_value > nums.back())
            return res;

        // special case where ksum reduced to twosum, calculate and return it
        if (k == 2)
            return twoSum(nums, target, start);

        // program counter reaches here means k>2, and we are suppose to reduce 'k' to 'k-1' every iteration
        // traversing the given vector
        for (int i = start; i < nums.size(); ++i)
        {
            // program control gets in, when "i" is equal to the given start index and it is not
            // duplicate (means not same as previouly calculated value)
            if (i == start || nums[i - 1] != nums[i])
            {
                for (vector<int> &subset : kSum(nums, static_cast<long>(target) - nums[i], i + 1, k - 1))
                {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }

        return res;
    }

    vector<vector<int>> twoSum(vector<int> &nums, int target, int start)
    {
        vector<vector<int>> res; // creating a VoV for string and returning the answer
        unordered_set<int> s;    // this will store the numbers for "nums" for faster lookup (eg: to get count)

        for (int i = start; i < nums.size(); ++i)
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

int main(int arg, char *argv[])
{
    Solution p;
    vector<int> num = {1, 0, -1, 0, -2, 2};
    int target = 0;

    // std::cout << num.back() << std::endl;

    PrintVoV(p.fourSum(num, 0));
    // std::cout<< p.fourSum() <<std::endl;
    return 0;
}