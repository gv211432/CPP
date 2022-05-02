// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        size_t i = 0;
        for (auto n : nums)
            if (n != nums[i])
                i++, nums[i] = n;

        return i + 1;
    }
};

void PrintVec(vector<int> &v, int n)
{
    std::cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i];
        (i + 1 < n) ? cout << ", " : cout << " ";
    }
    std::cout << "]" << std::endl;
}

int main(int arg, char *argv[])
{
    vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution s;

    PrintVec(v, s.removeDuplicates(v));
    return 0;
}