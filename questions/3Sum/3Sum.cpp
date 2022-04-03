// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

void PrintVoV(vector<vector<int>> vec)
{
    // printing the given vector of vector
    for (auto v : vec)
    {
        std::cout << "[ ";
        for (auto &n : v)
        {
            std::cout << n << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;        // creating contianer to hold the answer
        sort(nums.begin(), nums.end()); // sorting the given vector "nums" #O(nlogn)

        for (size_t i = 0; i < nums.size(); i++) // iterating throught the value of given vector #O(n^2)
        {
            if (i && (nums[i] == nums[i - 1])) // if its not the very first element
                continue;                      // if the previous value was equal to the current, skip iteration

            int l = i + 1, r = nums.size() - 1; // creating left and right pointers, for two pointer techinque
            while (l < r)                       // iterate till left is less than right
            {
                int threeSum = nums[i] + nums[l] + nums[r]; // storing the sum of three values
                if (threeSum > 0)                           // if sum is greater than 0 decrementing right pointer
                    r--;
                else if (threeSum < 0) // if sum is less then 0 increment left pointer
                    l++;
                else // if sum is equals to 0
                {
                    vector<int> v = {nums[i], nums[l], nums[r]};
                    ans.push_back(v); // pushing the triple vector in "ans" vector
                    l++;              // incrementing the left pointer till it points any new value
                                      // ( skipping duplicates in following loop)
                    while ((nums[l] == nums[l - 1]) && (l < r))
                        l++;
                }
            }
        }
        PrintVoV(ans);
        // return the "ans" vector of vector
        return ans;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    vector<int> v = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    s.threeSum(v);
    return 0;
}