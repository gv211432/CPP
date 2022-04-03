// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &h) // this is two pointer technique
    {
        // declaring the maxArea to hold the maximum area encountered till now
        // left and right index to iterate
        int maxArea = 0, l = 0, r = h.size() - 1;
        // iterate till "l" is less than "r"
        while (l < r)
        {
            // pick the max area form previous one or new smaller pole with distance between
            maxArea = max(maxArea, (min(h[l], h[r]) * (r - l)));
            // change the smallest pole
            (h[l] < h[r]) ? l++ : r--;
        }
        return maxArea;
    }
};

int main(int arg, char *argv[])
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution s;

    std::cout << s.maxArea(height) << std::endl;
    return 0;
}