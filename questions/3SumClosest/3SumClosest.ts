function threeSumClosest(nums: number[], target: number): number {
  let diff = Infinity; // declaring a diff variable with infinity value
  nums.sort((a, b) => a - b); // sorting the given array
  nums.forEach((e, i) => {
    // operating for every array value
    let [left, right] = [i + 1, nums.length - 1]; // declaring left and right pointers
    while (left < right) {
      let sum = e + nums[left] + nums[right]; // finding the sum of three current pointed numbers
      // loading the "diff" variable with least absolute value of difference of sum and target
      Math.abs(sum - target) < Math.abs(diff) ? (diff = target - sum) : null;
      // if sum is less than target increment left pointer to bring sum closer to 0
      sum < target ? left++ : right--;
    }
  });
  // return the difference
  return target - diff;
}

let arr = [-1, 2, 1, -4];
console.log(threeSumClosest(arr, 1));
