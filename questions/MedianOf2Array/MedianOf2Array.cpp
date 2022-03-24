// Main file of the Project
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &v1, vector<int> &v2) // O(N log N)
    {
        // sort first array in ascending order
        sort(v1.begin(), v1.end()); // O(N log N)
        // sort second array in ascending order
        sort(v2.begin(), v2.end()); // O(N log N)

        // create new array of size equals to the sum of given arrays for storing merged array
        vector<double> result(v1.size() + v2.size());

        // merging both given arrays, it will generate sorted merged array
        merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin()); // O(N log N)

        // applying formula to calculate median
        // if elements present in merged array in odd number
        if (result.size() % 2)                    // odd
            return (result[(result.size()) / 2]); // O(1)

        // if above is skipped means it is in even number
        return ((result[(result.size() - 1) / 2] / 2) + (result[(result.size() / 2)] / 2)); // O(1)
    }
};

class Solution2
{
public:
    double findMedianSortedArrays(vector<int> &v1, vector<int> &v2) // O(N log N)
    {
        // create new array of size equals to the sum of given arrays for storing merged array
        vector<double> result(v1.size() + v2.size());

        // merging the given two arrays with "2-way merge sort"
        size_t i = 0, j = 0, k = 0;
        while (i < v1.size() && j < v2.size()) // O(m+n)
        {
            if (v2[j] < v1[i])
                result[k++] = v2[j++];
            else
                result[k++] = v1[i++];
        }
        while (i < v1.size())      // O(n)
            result[k++] = v1[i++]; // copying the remiaining element of v1 i result array
        while (j < v2.size())      // O(n)
            result[k++] = v2[j++]; // copying the remiaining element of v2 i result array

        // applying formula to calculate median
        // if elements present in merged array in odd number
        if (result.size() % 2)                    // odd
            return (result[(result.size()) / 2]); // O(1)

        // if above is skipped means it is in even number
        return ((result[(result.size() - 1) / 2] / 2) + (result[(result.size() / 2)] / 2)); // O(1)
    }
};

int main(int arg, char *argv[])
{
    vector<int> v1 = {1111, 4, 5, 7, 8, 9, 10, 50};
    vector<int> v2 = {111, 44, 25, 97, 80, 29, 10, 540};
    Solution2 s;
    std::cout << s.findMedianSortedArrays(v1, v2) << std::endl;
    return 0;
}