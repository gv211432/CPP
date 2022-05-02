// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

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

void PrintV(vector<int> v)
{
    std::cout << "[ ";
    for (auto n : v)
        std::cout << n << ", ";
    std::cout << "]" << std::endl;
}

// Useless by gaurav
class Solution2
{
    void combination(vector<int> &candidates, int target, vector<int> &part,
                     int index, int sum, vector<vector<int>> &ans,
                     map<vector<int>, char> &seen)
    {
        if (sum > target)
            return;
        if (seen.count(part) == 0 and sum == target)
        {
            ans.push_back(part);
            seen.emplace(part, '1');
            return;
        }
        for (size_t i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i + 1])
                continue;

            part.push_back(candidates[i]);
            combination(candidates, target, part, i + 1, sum + candidates[i], ans, seen);
            part.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // PrintV(candidates);
        vector<vector<int>> ans = {};
        vector<int> part = {};
        map<vector<int>, char> seen = {};
        sort(candidates.begin(), candidates.end());
        // PrintV(candidates);

        // vector<int>::iterator itr = unique(candidates.begin(), candidates.end());
        // PrintV(candidates);

        // candidates.resize(distance(candidates.begin(), itr));
        // PrintV(candidates);

        combination(candidates, target, part, 0, 0, ans, seen);
        return ans;
    }
};

/*
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> results = new ArrayList<>();
        LinkedList<Integer> comb = new LinkedList<>();

        Arrays.sort(candidates);

        backtrack(candidates, comb, target, 0, results);
        return results;
    }

    private void backtrack(int[] candidates, LinkedList<Integer> comb,
                           Integer remain, Integer curr,
                           List<List<Integer>> results) {
        if (remain == 0) {
            // copy the current combination to the final list.
            results.add(new ArrayList<Integer>(comb));
            return;
        }

        for (int nextCurr = curr; nextCurr < candidates.length; ++nextCurr) {
            if (nextCurr > curr && candidates[nextCurr] == candidates[nextCurr - 1])
                continue;

            Integer pick = candidates[nextCurr];
            // optimization: early stopping
            if (remain - pick < 0)
                break;

            comb.addLast(pick);
            backtrack(candidates, comb, remain - pick, nextCurr + 1, results);
            comb.removeLast();
        }
    }
}
*/

// useful by leetcode
class Solution
{
    void backtrack(vector<int> &candidates, vector<int> &part, int remain, int index, vector<vector<int>> &result)
    {
        if (remain == 0)
        {
            result.push_back(part);
            return;
        }

        for (size_t i = index; i < candidates.size(); i++)
        {
            // let the current element to be added int the part(solution)
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            int pick = candidates[i];
            // early stop, befor next backtracking interation
            if (remain - pick < 0)
                break;

            part.push_back(pick);
            backtrack(candidates, part, remain - pick, i + 1, result);
            part.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result = {};
        vector<int> part = {};
        sort(candidates.begin(), candidates.end()); // sorting candidates
        backtrack(candidates, part, target, 0, result);
        return result;
    }
};

int main(int arg, char *argv[])
{

    Solution s;
    vector<int> v = {10, 1, 2, 7, 6, 1, 5};
    int t = 8;
    // vector<int> v1 = {1, 2, 3, 5};
    // int t1 = 8;
    PrintVOV(s.combinationSum2(v, t));
    // PrintVOV(s.combinationSum2(v1, t1));
    std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}