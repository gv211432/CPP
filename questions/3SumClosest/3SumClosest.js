function threeSumClosest(nums, target) {
    var diff = Infinity; // declaring a diff variable with infinity value
    nums.sort(function (a, b) { return a - b; }); // sorting the given array
    nums.forEach(function (e, i) {
        // operating for every array value
        var _a = [i + 1, nums.length - 1], left = _a[0], right = _a[1]; // declaring left and right pointers
        while (left < right) {
            var sum = e + nums[left] + nums[right];
            Math.abs(sum - target) < Math.abs(diff) ? (diff = target - sum) : null;
            sum < target ? left++ : right--;
        }
    });
    return target - diff;
}
var arr = [-1, 2, 1, -4];
console.log(threeSumClosest(arr, 1));
