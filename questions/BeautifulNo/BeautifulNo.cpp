// Main file of the Project
// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int arg, char *argv[])
{
    size_t len = 0;
    std::cout << "Lenght of the array: ";
    std::cin >> len;

    for (size_t i = 0; i < len; i++)
    {
        size_t numLen = 0;
        cin >> numLen;

        vector<int> num;

        for (size_t j = 0; j < numLen; j++)
        {
            int n = 0;
            cin >> n;
            num.push_back(n);
        }

        // =================================
        sort(num.begin(), num.end());

        for (auto element : num)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl;

        int mid = num.size() / 2;
        int odd = num.size() % 2;

        if (odd)
        {
            if (mid % 2)
            {
                // incermental order
            }
            else
            {
                // incermental order
            }
        }
        else
        {
            // any case will work fine
            std::cout << "Hi" << std::endl;
        }

        std::cout << mid << std::endl;
    }

    return 0;
}