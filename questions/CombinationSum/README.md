<!-- ┏━┓╻  ╻     ┏━┓┏┓ ┏━┓╻ ╻╺┳╸   ┏━╸┏━┓┏┳┓┏┓ ╻┏┓╻┏━┓╺┳╸╻┏━┓┏┓╻┏━┓╻ ╻┏┳┓ -->
<!-- ┣━┫┃  ┃     ┣━┫┣┻┓┃ ┃┃ ┃ ┃    ┃  ┃ ┃┃┃┃┣┻┓┃┃┗┫┣━┫ ┃ ┃┃ ┃┃┗┫┗━┓┃ ┃┃┃┃ -->
<!-- ╹ ╹┗━╸┗━╸   ╹ ╹┗━┛┗━┛┗━┛ ╹    ┗━╸┗━┛╹ ╹┗━┛╹╹ ╹╹ ╹ ╹ ╹┗━┛╹ ╹┗━┛┗━┛╹ ╹ -->

39. Combination Sum
    Medium

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:

Input: candidates = [2], target = 1
Output: []

Constraints:

    1 <= candidates.length <= 30
    1 <= candidates[i] <= 200
    All elements of candidates are distinct.
    1 <= target <= 500

Solution: backtracking

1. If the sum of the current combination is greater than target, then even if we move forward with this combination, the sum will only increase, so there is no fun to moving further with such a combination as we can never achieve the target sum from this. So backtrack from this.
2. If the sum of the current combination is equal to the target, then we have a solution, so store this combination in the answers. Now moving forward with this combnation also will only increase the sum and we can't achieve the target sum again from this ever. So backtrack from here.
3. if we are here then that means the sum of the combination is still less that the target sum, and we have a scope of finding a combination whose sum can be equal to the target.
   i) Now consider all possible options into this combination, one at a time.
   ii) Go check if considering the current option can give us the solution.
   iii) Now when this option backtracks to this place again, now remove this option and try another option. e.g. at [2, 2, _ ] we have 3 options to fill the 3rd place i.e. [2, 3, 5].
   So firstly we will go on with [2, 2, 2]. Then when this backtracks to this place again, remove the last 2 and try the next option which is 3 that means [2, 2, 3].
   When this also backtracks remove 3 to try 5, that means [2, 2, 5].
   Now as all the options are exhausted for [2, 2, _ ], now backtrack to its previous state which is [2, 2], and so on...
