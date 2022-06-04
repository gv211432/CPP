// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    { //   take a look at screenshot for better understanding
        // strating form the top of the stairs and coming down by calculating the minimum cost by taking
        // min of next two stairs, hence starting form third last top stair
        for (int i = cost.size() - 3; i >= 0; i--)
            // taking minimum of next two stairs and adding own cost, makes it absolute stair cost
            cost[i] += min(cost[i + 1], cost[i + 2]),
                // printing for debugging
                std::cout << "i : " << cost[i] << std::endl;
        return min(cost[0], cost[1]); // return the minimum of first two available absolute strair cost
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    vector<int> v = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::cout << s.minCostClimbingStairs(v) << std::endl;
    return 0;
}