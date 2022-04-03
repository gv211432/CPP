function threeSum(nums: number[]): number[][] {
  //   console.log("Given length is : ", nums.length);
  let ans: number[][] = []; // this will hold the answer array

  //   nums.sort(); // sorting the given array, this default sort is useless never use it!!
  nums.sort((a, b) => a - b);

  nums.forEach((e, i) => {
    // if array element is not same as previous one
    if (!(i && nums[i] === nums[i - 1])) {
      let left = i + 1; // left pointer and right pointer to apply two pointer technique
      let right = nums.length - 1;

      // iterate till left is less than right pointer
      while (left < right) {
        let threeSum = nums[i] + nums[left] + nums[right]; // sum of three numbers

        if (threeSum > 0)
          right -= 1; // is sum is greater than 0, decrement right
        else if (threeSum < 0)
          left += 1; // if sum is less than 0, increment left
        else {
          // else pushing the triplet in the a new array
          // let n = [nums[i], nums[left], nums[right]];
          ans.push([nums[i], nums[left], nums[right]]); // pushing new array to answer array
          left += 1; // incrementing the left pointer till points new unique value
          while (nums[left] === nums[left - 1] && left < right) left += 1;
        }
      }
    }
  });
  // returning the answer array
  return ans;
}

// console.log(threeSum([-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4]));
// console.log(threeSum([-1, 0, 1, 2, -1, -4]));
// console.log(threeSum([-1, -1, -4, 0, 1, 2]));
// console.log(threeSum([0, 0]));
