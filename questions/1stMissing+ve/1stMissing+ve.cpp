// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // sorting the given vector
        int m = 1;                      // smallest postive number
        for (auto n : nums)
            if (n == m) // if smallest postive number is present in vector, increment by 1
                m++;
        return m;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    vector<int> n1 = {7, 8, 9, 11, 12};
    vector<int> n2 = {1, 2, 0};
    vector<int> n3 = {3, 4, -1, 1};
    std::cout << s.firstMissingPositive(n1) << std::endl;
    std::cout << s.firstMissingPositive(n2) << std::endl;
    std::cout << s.firstMissingPositive(n3) << std::endl;
    return 0;
}