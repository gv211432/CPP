function threeSum(nums) {
    //   console.log("Given length is : ", nums.length);
    var ans = []; // this will hold the answer array
    //   nums.sort(); // sorting the given array, this default sort is useless never use it!!
    nums.sort(function (a, b) { return a - b; });
    nums.forEach(function (e, i) {
        // if array element is not same as previous one
        if (!(i && nums[i] === nums[i - 1])) {
            var left = i + 1; // left pointer and right pointer to apply two pointer technique
            var right = nums.length - 1;
            // iterate till left is less than right pointer
            while (left < right) {
                var threeSum_1 = nums[i] + nums[left] + nums[right]; // sum of three numbers
                if (threeSum_1 > 0)
                    right -= 1; // is sum is greater than 0, decrement right
                else if (threeSum_1 < 0)
                    left += 1; // if sum is less than 0, increment left
                else {
                    // else pushing the triplet in the a new array
                    // let n = [nums[i], nums[left], nums[right]];
                    ans.push([nums[i], nums[left], nums[right]]); // pushing new array to answer array
                    left += 1; // incrementing the left pointer till points new unique value
                    while (nums[left] === nums[left - 1] && left < right)
                        left += 1;
                }
            }
        }
    });
    // returning the answer array
    return ans;
}
console.log(threeSum([-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4]));
console.log(threeSum([-1, 0, 1, 2, -1, -4]));
console.log(threeSum([-1, -1, -4, 0, 1, 2]));
console.log(threeSum([0, 0]));
