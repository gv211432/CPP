// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        size_t i = 0;
        for (auto n : nums)
            if (n != val)
                nums[i] = n, i++;
        return i;
    }
};

void PrintVector(vector<int> &v, size_t n)
{
    std::cout << "[ ";
    for (size_t i = 0; i < n; i++)
    {
        std::cout << v[i];
        (i + 1 < n) ? cout << ", " : cout << " ";
    }
    std::cout << "]" << std::endl;
}

int main(int arg, char *argv[])
{
    vector<int> u = {0, 1, 2, 2, 3, 0, 4, 2};
    vector<int> v = {2};
    vector<int> z = {3, 3};

    Solution s;

    // std::cout << s.removeElement(v, 3) << std::endl;
    PrintVector(u, s.removeElement(u, 2));
    PrintVector(v, s.removeElement(v, 3));
    PrintVector(z, s.removeElement(z, 3));

    std::cout
        << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}