// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

// Using stacks
class Solution
{
public:
    int trap(vector<int> &height)
    {
        // answer variable and current index of the array
        size_t ans = 0, current = 0;
        stack<int> st = {}; // stack pointer to store the maximum height
        while (current < height.size())
        {
            while (!st.empty() && height[current] > height[st.top()])
            {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int dist = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += dist * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};

// // two pointer technique
// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         // left pointer and right pointer
//         int l = 0, r = height.size() - 1;
//         // answer variable, max left value and max right value variables
//         int ans = 0, left_max = 0, right_max = 0;
//         while (l < r)
//         {
//             if (height[l] < height[r]) // left pointer is smaller than right pointer
//             {
//                 //
//                 (height[l] >= left_max) ? left_max = height[l]
//                                         : ans += left_max - height[l];
//                 l++;
//             }
//             else
//             {
//                 height[r] >= right_max ? right_max = height[r] : ans += right_max - height[r];
//                 r--;
//             }
//         }
//         return ans;
//     }
// };

int main(int arg, char *argv[])
{
    Solution s;
    vector<int> t = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> q = {4, 2, 0, 3, 2, 5};
    std::cout << s.trap(t) << std::endl;
    std::cout << s.trap(q) << std::endl;
    return 0;
}