// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

// Reference
// class Solution {
//     void combination(vector<int>& candidates, int target, vector<int> &currComb, int currSum, int currIndex, vector<vector<int>>& ans){
//         if(currSum>target) return; //backtrack
//         if(currSum==target){
//             ans.push_back(currComb); //store the solution and backtrack
//             return;
//         }

//         for(int i=currIndex; i<candidates.size(); i++){ //try all possible options for the next level
//             currComb.push_back(candidates[i]); //put 1 option into the combination
//             currSum+=candidates[i];
//             combination(candidates, target, currComb, currSum, i, ans); //try with this combination, whether it gives a solution or not.
//             currComb.pop_back(); //when this option backtrack to here, remove this and go on to the next option.
//             currSum-=candidates[i];
//         }

//     }
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> ans;
//         vector<int> currComb={};
//         combination(candidates, target, currComb, 0, 0, ans);
//         return ans;
//     }
// };

class Solution
{
    // this is backtracking
    void combination(vector<int> &candidates, int target, vector<int> &part, int sum, int index, vector<vector<int>> &ans)
    {
        if (sum > target) // termination condition block
            return;
        if (sum == target) // found solution block
        {
            ans.push_back(part);
            return;
        }

        for (size_t i = index; i < candidates.size(); i++) // new combination generation block
        {
            part.push_back(candidates[i]);
            combination(candidates, target, part, sum + candidates[i], i, ans);
            part.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans = {};
        vector<int> part = {};
        combination(candidates, target, part, 0, 0, ans);
        return ans;
    }
};

void PrintVOV(vector<vector<int>> vec)
{
    for (auto v : vec)
    {
        std::cout << "[ ";
        for (auto n : v)
            std::cout << n << ", ";
        std::cout << "]" << std::endl;
    }
}

int main(int arg, char *argv[])
{
    Solution s;

    vector<int> v = {2, 3, 6, 7};
    int t = 7;
    PrintVOV(s.combinationSum(v, t));

    std::cout << "=================" << std::endl;

    vector<int> v1 = {2, 3, 5};
    int t1 = 8;
    PrintVOV(s.combinationSum(v1, t1));

    return 0;
}