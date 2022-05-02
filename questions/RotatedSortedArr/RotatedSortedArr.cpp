
#include <bits/stdc++.h>
using namespace std;

/*
function search(nums: number[], target: number): number {
    const n: number = nums.length;
    let left: number = 0;
    let right: number = n -1;

    while(left <= right)
    {
        let mid = Math.floor((left + right)/ 2);
        if (target == nums[mid]) return mid;

        //search left sorted array
        if (nums[left] <= nums[mid])
        {
            if (target > nums[mid] || target < nums[left])
                left = mid + 1;
            else
                right = mid -1;
        }
        else {
           if (target < nums[mid] || target > nums[right])
                right = mid - 1;
            else
                left = mid + 1;
        }
    };
    return -1;
};
*/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        size_t n = nums.size();

        int left = 0, right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
                return mid;

            if (nums[left] <= nums[mid])
            {
                if (target > nums[mid] or target < nums[left])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            {
                if (target < nums[mid] or target > nums[right])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};

int main(int arg, char *argv[])
{
    Solution s;

    // vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    // int target = 0;
    // std::cout << s.search(v, target) << std::endl;

    vector<int> v1 = {4, 5, 6, 7, 0, 1, 2};
    int t1 = 0;

    for (auto v : v1)
        std::cout << v << ", ";

    std::cout << std::endl;
    std::cout << "Enter your number : ";
    cin >> t1;

    std::cout << s.search(v1, t1) << std::endl;

    return 0;
}