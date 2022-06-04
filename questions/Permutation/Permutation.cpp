// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

void PrintHashMap(unordered_map<int, int> hash_map)
{
    for (auto h : hash_map)
        std::cout << h.first << " <= qty : " << h.second << endl;
}

class Solution
{
private:
    // Backtracking, fastest and slim
    void dfs(vector<int> &nums, vector<vector<int>> &ans, int index = 0)
    {
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int j = index; j < nums.size(); j++)
        {
            swap(nums[j], nums[index]);
            dfs(nums, ans, index + 1);
            swap(nums[j], nums[index]);
        }
    }

    void dfs_unique(int &size, unordered_map<int, int> &hash_map, vector<vector<int>> &ans, vector<int> &perm)
    {
        if (perm.size() >= size) // when size of temperory vector is equals to the size of given number
        {                        // of elements in problem, means one permutation is ready
            ans.push_back(perm);
            return;
        }

        // never forget to take reference of elements in case of updating them
        for (auto &h : hash_map)
        {
            if (h.second > 0)
            {
                perm.push_back(h.first); // push the elements one by one in temperory vector
                // std::cout << h.first << "<= Org " << h.second << std::endl;
                h.second = h.second - 1; // also decrement the qty of elements
                // std::cout << h.first << "<= Dec " << h.second << std::endl;
                dfs_unique(size, hash_map, ans, perm);
                h.second = h.second + 1; // after creating one permutatin increment it
                // std::cout << h.first << "<= Inc " << h.second << std::endl;
                perm.pop_back(); // and remove the element form temperory vector, so that
                                 // in next iteration new permutation will be generated
            }
        }
    }

public:
    // ┏━┓┏━┓╻  ╻ ╻╺┳╸╻┏━┓┏┓╻╺┓
    // ┗━┓┃ ┃┃  ┃ ┃ ┃ ┃┃ ┃┃┗┫ ┃
    // ┗━┛┗━┛┗━╸┗━┛ ╹ ╹┗━┛╹ ╹╺┻╸
    // backtracking
    vector<vector<int>> permute1(vector<int> &nums)
    {
        vector<vector<int>> ans;
        dfs(nums, ans);
        return ans;
    }

    // ┏━┓┏━┓╻  ╻ ╻╺┳╸╻┏━┓┏┓╻   ┏━┓
    // ┗━┓┃ ┃┃  ┃ ┃ ┃ ┃┃ ┃┃┗┫   ┏━┛
    // ┗━┛┗━┛┗━╸┗━┛ ╹ ╹┗━┛╹ ╹   ┗━╸
    // backtracking here as well
    vector<vector<int>> permute2(vector<int> &nums)
    {
        vector<vector<int>> ans = {};

        for (size_t i = 0; i < nums.size(); i++)
        {
            int n = nums[0];
            nums.erase(nums.begin());

            if (nums.size() == 0)
            {
                nums.push_back(n);
                return {nums};
            }

            vector<vector<int>> p = permute2(nums);
            for (size_t j = 0; j < p.size(); j++)
            {
                p[j].push_back(n);
                ans.push_back(p[j]);
            }
            nums.push_back(n);
        }

        return ans;
    }

    // ┏━┓┏━┓╻  ╻ ╻╺┳╸╻┏━┓┏┓╻   ┏━┓
    // ┗━┓┃ ┃┃  ┃ ┃ ┃ ┃┃ ┃┃┗┫   ╺━┫
    // ┗━┛┗━┛┗━╸┗━┛ ╹ ╹┗━┛╹ ╹   ┗━┛
    // this funtion might get duplicate elements
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        unordered_map<int, int> hash_map = {};
        // creating hash map for tracking duplicates of same elements
        for (auto n : nums)
            if (hash_map.count(n) >= 1) // if element is present in hash map, increment the qty
                hash_map.find(n)->second++;
            else
                hash_map.emplace(make_pair(n, 1)); // if not present, add it in hash map
        // PrintHashMap(hash_map);              // debuging function
        vector<vector<int>> ans = {};          // answer varaible
        vector<int> perm = {};                 // temperory permution variable
        int size = nums.size();                // qty of the required element in one permutation
        dfs_unique(size, hash_map, ans, perm); // backtracking for solution
        return ans;                            // return found solution
    }

    // ┏━┓┏━┓╻  ╻ ╻╺┳╸╻┏━┓┏┓╻   ╻ ╻
    // ┗━┓┃ ┃┃  ┃ ┃ ┃ ┃┃ ┃┃┗┫   ┗━┫
    // ┗━┛┗━┛┗━╸┗━┛ ╹ ╹┗━┛╹ ╹     ╹
    vector<vector<int>> permute_unique(vector<int> &nums)
    {
        // next_permutation is to find next lexicographically greater value for given array of values.
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do
        {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }

private:
    void solve(vector<vector<int>> &ans, int index, vector<int> &nums)
    {
        if (index >= nums.size() - 1)
        {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for (int i = index; i < nums.size(); i++)
        {
            if (st.count(nums[i]))
                continue;

            st.insert(nums[i]);
            swap(nums[index], nums[i]);
            solve(ans, index + 1, nums);
            swap(nums[index], nums[i]);
        }
    }

public:
    // ┏━┓┏━┓╻  ╻ ╻╺┳╸╻┏━┓┏┓╻   ┏━╸
    // ┗━┓┃ ┃┃  ┃ ┃ ┃ ┃┃ ┃┃┗┫   ┗━┓
    // ┗━┛┗━┛┗━╸┗━┛ ╹ ╹┗━┛╹ ╹   ┗━┛
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {

        vector<vector<int>> ans;
        int index = 0;
        solve(ans, index, nums);
        return ans;
    }
};

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

int main(int arg, char *argv[])
{
    Solution s;
    vector<int> v = {1, 1, 3};
    PrintVoV(s.permuteUnique(v));
    return 0;
}