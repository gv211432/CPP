// Main file of the Project
#include <bits/stdc++.h>
#include "../CreateTable/CreateTable.cpp"
#include "../utilities/utilities.h"
using namespace std;
// utility function for printing Vector of Vector
void print_vov(vector<vector<int>> v)
{
    for (auto x : v)
    {
        std::cout << "{ ";
        for (auto &n : x)
            std::cout << n, &n == &x.back() ? cout << " " : cout << ", ";
        std::cout << "}" << std::endl;
    }
}

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // print_vov(matrix);
        std::cout << "Original Matrix" << std::endl;
        for (size_t i = 0; i < matrix.size(); i++)
            for (size_t j = i + 1; j < matrix[0].size(); j++)
                swap(matrix[i][j], matrix[j][i]);
        // print_vov(matrix);
        std::cout << "Transpose of Matrix" << std::endl;

        for (auto &r : matrix)
            reverse(r.begin(), r.end());
        std::cout << "90 deg Rotation of Matrix" << std::endl;
    }
};

int main(int arg, char *argv[])
{
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> u = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

    Solution s;
    // s.rotate(v);
    // s.rotate(u);
    // boxes::table_with_content(v);
    // boxes::table_with_content(u);

    int arr[] = {1, 2, 3, 4};
    vector<int> vec = {1, 2, 3, 4};
    print_v::print_arr(vec);
    print_v::print_arr(arr, 4);
    return 0;
}