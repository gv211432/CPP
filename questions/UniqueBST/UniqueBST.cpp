// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int numTrees(int n) // Time O(N^2) and Space O(N)
//     {
//         vector<int> num_tree(n + 1, 1);
//         for (size_t i = 2; i < n + 1; i++)
//         {
//             int total = 0;
//             for (size_t j = 1; j < i + 1; j++)
//                 total += num_tree[j - 1] * num_tree[i - j];
//             num_tree[i] = total;
//         }
//         return num_tree[n];
//     }
// };

class Solution
{
public:
    int numTrees(int n) // Time O(N^2) and Space O(N)
    {
        // Mind this : 0 node = 1 tree, 1 node = 1 tree
        // Consider this case: numTrees(4)
        // = numTrees(0) + numTrees(3)
        //   numTrees(1) + numTrees(2)
        //   numTrees(2) + numTrees(1)
        //   numTrees(3) + numTrees(0)
        // = 1*5 + 1*2 + 1*2 + 5*1 = 14

        // declare a vector of length "n+1" with 1 as defaut value
        vector<int> num_tree(n + 1, 1);
        for (size_t node = 2; node < n + 1; node++)
        {
            int total = 0;
            // if 1 becomes root the left_node = 0 and right_node = 3 and so on..
            for (size_t root = 1; root < node + 1; root++)
            {
                int l = root - 1, r = node - root;
                total += num_tree[l] * num_tree[r];
            }
            num_tree[node] = total;
        }
        return num_tree[n];
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    std::cout << s.numTrees(3) << std::endl;
    std::cout << s.numTrees(4) << std::endl;
    std::cout << s.numTrees(5) << std::endl;
    return 0;
}