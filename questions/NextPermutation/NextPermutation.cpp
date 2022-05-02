// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

/*
public class Solution {
    public void nextPermutation(int[] nums) {
        int i = nums.length - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.length - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
    }

    private void reverse(int[] nums, int start) {
        int i = start, j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
*/
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i])
            i--;

        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main(int arg, char *argv[])
{
    vector<int> v = {1, 2, 3, 8, 9, 4};
    Solution s;
    s.nextPermutation(v);

    for (auto e : v)
        std::cout << e << std::endl;

    return 0;
}