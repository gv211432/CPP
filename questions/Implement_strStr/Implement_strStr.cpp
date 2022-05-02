// Main file of the Project
#include <bits/stdc++.h>
using namespace std;
#define NOP 1 + 1

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        // if (needle == "")
        //     return 0;
        // if (haystack == "")
        //     return -1;

        // unsigned int i = 0, j = 0;
        // while (haystack[i] && needle[j])
        //     (haystack[i++] == needle[j++]) ? NOP : j = 0;

        // return (j == needle.size()) ? i - needle.size() : -1;
        return haystack.find(needle);
    }
};

int main(int arg, char *argv[])
{
    string haystack = "heello", needle = "eel";
    Solution s;

    // std::cout << haystack.substr(s.strStr(haystack, needle), needle.size()) << std::endl;
    std::cout << s.strStr(haystack, needle) << std::endl;
    std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}