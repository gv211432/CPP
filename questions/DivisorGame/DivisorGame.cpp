// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool divisorGame(int n)
    {
        // if input is even alice wins the game, simple and sweet :)
        return n % 2 ? 0 : 1;
    }
};

int main(int arg, char *argv[])
{
    Solution s;

    std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}