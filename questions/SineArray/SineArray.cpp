// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printSinArr()
    {

        vector<int> v;
        for (int deg = 0; deg < 180; deg += 10)
        {
            double rad = deg * (3.14159 / 180);
            double tempSin = sin(rad);

            v.push_back((tempSin * 259));
        }

        std::cout << "No. of elements present : " << v.size() << std::endl;

        for (auto n : v)
        {
            std::cout << n << ",";
        }
        for (auto i = v.rbegin() + 1; i < v.rend() - 1; i++)
        {
            std::cout << *i << ",";
        }

        std::cout << std::endl;
    }
};

int main(int arg, char *argv[])
{
    Solution s;

    s.printSinArr();
    // std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}