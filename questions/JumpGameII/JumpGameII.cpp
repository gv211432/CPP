// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // jump game I
    bool canJump(vector<int> &nums)
    {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            std::cout << "i : " << i << std::endl;
            if (i + nums[i] >= goal)
                goal = i;
        }
        return goal == 0;
    }

    int vector_max(vector<int>::iterator l, vector<int>::iterator r)
    {
        int max_value = 0;
        while (l < r)
            max_value = max(*l, max_value), l++;
        return max_value;
    }
    // self made but useless
    int jump_my(vector<int> &nums)
    {
        int ans = 0, l = 0, r = 0;
        while (r < nums.size() - 1)
        {
            int farthest = 0;
            farthest = vector_max(nums.begin() + l, nums.begin() + r + 1);
            l = r + 1, r += farthest, ans += 1;
            std::cout << farthest << std::endl;
        }
        return ans;
    }

    // self made but usefullll (greedy approach)
    int jump(vector<int> &nums) // O(N)
    {
        // answer variable, left and right position tracker
        int ans = 0, l = 0, r = 0;
        while (r < nums.size() - 1)
        {
            int far = 0; // temperory variable to store farthest access

            for (int i = l; i <= r; i++)
                if ((nums[i] + i) > (far)) // if sum of number and its index is greater
                    far = nums[i] + i;     // than previons such encounters, please update

            l = r + 1, r = far, ans += 1; // after every iteration, increment the ans by 1
        }
        return ans;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    vector<int> n = {0};
    vector<int> o = {1, 2, 1, 5, 1};
    vector<int> m = {3, 4, 3, 2, 5, 4, 3};
    vector<int> q = {2, 3, 1, 1, 4};
    // s.canJump(n) ? std::cout << "True" << std::endl : std::cout << "False" << std::endl;
    std::cout << s.jump(m) << std::endl;
    std::cout << s.jump(o) << std::endl;
    std::cout << s.jump(q) << std::endl;
    return 0;
}