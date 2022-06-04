// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // helping function to recurse on vector of prices to find maximum profit
    int recurse(vector<int> &prices, int index = 0, bool is_buying = true)
    {
        if (index >= prices.size()) // if index goes out of bound return 0
            return 0;

        if (is_buying) // if is_buying is true buy the curren stocks and substract the price with current profit
            return max(recurse(prices, index + 1, false) - prices[index],
                       recurse(prices, index + 1, true)); // and return the maximum profit on buying or skipping

        else // else sell the current stocks and add the price to the curent profit
            return max(recurse(prices, index + 2, true) + prices[index],
                       recurse(prices, index + 1, false)); // and return the maximum profit on selling or skipping
    }

public:
    int maxProfit(vector<int> &prices)
    {
        return recurse(prices); // pure recursion
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    vector<int> v1 = {1, 2, 3, 0, 2};
    vector<int> v2 = {1};
    vector<int> v3 = {2, 1};
    vector<int> v4 = {1, 2};
    // s.maxProfit(v);
    std::cout << s.maxProfit(v1) << std::endl;
    std::cout << s.maxProfit(v2) << std::endl;
    std::cout << s.maxProfit(v3) << std::endl;
    std::cout << s.maxProfit(v4) << std::endl;
    return 0;
}