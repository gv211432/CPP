// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // two pointer technique
    int maxProfit(vector<int> &prices)
    {
        int l = 0, r = 1, profit = 0;
        while (r < prices.size())
        {
            if (prices[l] < prices[r])                       // if value at 'l' is smaller than 'r'
                profit = max(prices[r] - prices[l], profit); // update the maximum value in profit
            else
                l = r; // if value at 'r' is less than 'l', make update 's'
            r += 1;    // for every iteration increment 'r' by 1
        }
        return profit;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(v) << endl;
    vector<int> u = {7, 6, 4, 3, 1};
    cout << s.maxProfit(u) << endl;
    vector<int> w = {2, 1, 2, 0, 1, 2};
    std::cout << s.maxProfit(w) << std::endl;
    return 0;
}