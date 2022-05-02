// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

/*
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 1:
            if nums[0] == target:
                return [0,0]
            return [-1,-1]

        l = 0
        r = len(nums)-1

        while l < r:
            if nums[l] < target:
                l += 1

            if nums[r] > target:
                r -= 1

            if nums[l] == target and nums[r] == target:
                return [l, r]

        return [-1, -1]
*/

// Binary search and linear after find the mathing element to find out range
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> v = {-1, -1};
        int n = nums.size();

        int l = 0, r = n - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == target)
            {
                l = m, r = m; // making l and r and lower and upper bound of the element to be found
                while (l - 1 >= 0 and nums[l - 1] == target)
                    l--;
                while (r + 1 < n and nums[r + 1] == target)
                    r++;

                v.clear(), v.push_back(l), v.push_back(r);
                return v;
            }
            else
                (target < nums[m]) ? r = m - 1 : l = m + 1;
        }
        return v;
    }
};

// Two pointer technique
class Solution1
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> v1 = {-1, -1};
        vector<int> v0 = {0, 0};

        if (nums.size() == 1)
        {
            if (nums[0] == target)
                return v0;
            return v1;
        }

        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            if (nums[l] < target)
                l += 1;
            if (nums[r] > target)
                r -= 1;

            if (nums[l] == target and nums[r] == target)
            {
                v0.clear();
                v0.push_back(l), v0.push_back(r);
                return v0;
            }
        }

        return v1;
    }
};

class Solution2
{
    int lower_bound(vector<int> &nums, int target)
    {

        int l = 0,
            h = nums.size() - 1,
            lower_bound = -1;
        while (l <= h)
        {

            int mid = (l + h) / 2;
            if (nums[mid] == target)
                lower_bound = mid, h = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return lower_bound;
    }

    int upper_bound(vector<int> &nums, int target)
    {

        int l = 0,
            h = nums.size() - 1,
            upper_bound = -1;

        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] == target)
                upper_bound = mid, l = mid + 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return upper_bound;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> v = {lower_bound(nums, target), upper_bound(nums, target)};
        return v;
    }
};

class Solution3
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // index for last element
        int last = nums.size() - (int)(find(nums.rbegin(), nums.rend(), target) - nums.rbegin()) - 1;
        // index for first element but not sure, because if no element found temp = length of given vector
        int temp = (int)(find(nums.begin(), nums.end(), target) - nums.begin());

        // if last is -1 then put first also  as -1, means no element in the given vector
        // if last element exist means temp is valid, use it
        vector<int> v = {(last == -1) ? -1 : temp, last};
        return v;
    }
};

int main(int arg, char *argv[])
{
    Solution3 s;
    vector<int> v1 = {5, 7, 7, 8, 8, 8, 8, 8, 8, 10};
    // vector<int> v1 = {0, 1, 2, 3, 4, 4, 4};
    // vector<int> v1 = {1};
    // int t1 = 6;
    int t1 = 6;

    std::cout << s.searchRange(v1, t1)[0] << "  " << s.searchRange(v1, t1)[1] << std::endl;
    return 0;
}