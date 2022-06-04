// Main file of the Project
#include <bits/stdc++.h>
#include "../utilities/utilities.h"
using namespace std;

class Solution
{
public:
    int fibonacci(int n, unordered_map<int, int> &m)
    {
        if (n == 0 || n == 1)
            return 1;
        else if (m.find(n) != m.end())
            return m.find(n)->second;

        int f = fibonacci(n - 1, m) + fibonacci(n - 2, m);
        m.emplace(make_pair(n, f));
        return f;
    }

    //  see screenshot for clear idea we are try to do, it is linear dynamic programming
    int climbStairs(int n)
    {
        // Solution 1:
        // solution with vector and will show clarity what we are trying to do
        // vector<int> dp(n + 1, 0);
        // for (int i = n; i >= 0; i--)
        // {
        //     if (i == n)
        //         dp[i] = 1;
        //     else if (i == n - 1)
        //         dp[i] = 1;
        //     else
        //         dp[i] = dp[i + 1] + dp[i + 2];
        // }
        // std::cout << dp[0] << std::endl;
        // return dp[0];

        // Solution 2: O(N/2) = O(N)
        // let last two steps be 1, where 'a' is second last and 'b' is last
        int a = 1, b = 1, n_copy = n; // take copy of 'n' for later determining odd or even number
        n /= 2;                       // divide the given number by 2 becuase will be calculate two steps in one iteration
        while (n > 0)                 // and step will sum of its previous two steps, updating it in 'a' and 'b' itself
            b += a, a += b, n--;      // decrement the 'n' by 1
        return n_copy % 2 ? a : b;    // if n is odd return 'a' else 'b'

        // Solution 3:
        // unordered_map<int, int> m = {};
        // return fibonacci(n, m);
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    // std::cout << s.climbStairs(4)
    //           << std::endl;
    // std::cout << s.climbStairs(5)
    //           << std::endl;
    // std::cout << s.climbStairs(7)
    //           << std::endl;
    return 0;
}