// Main file of the Project
// debug this is accepted by leetcode
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    size_t lengthOfLongestSubstring(string s)
    {
        // this index will point the start position of substring
        size_t i = 0;
        size_t ans = 0;
        map<char, size_t> m;

        // the substring between the 'i' and 'j' will be the longest substring with length in 'ans'
        for (size_t j = 0; j < s.size(); j++)
        {
            // j is the current index of the character in the string
            // if character is present in the map 'm'
            if (!(m.find(s[j]) == m.end()))
            {
                i = max(m.find(s[j])->second, i);
                m.find(s[j])->second = j + 1;
            }
            else
            {
                // character is not present in map 'm', create new pair of character and the j+1
                m.insert(make_pair(s[j], (j + 1)));
            }
            ans = max(ans, (j + 1 - i));

            // std::cout << ans << std::endl;
        }

        for (auto x : m)
        {
            std::cout << x.first << " => " << x.second << std::endl;
        }
        // std::cout << ans << std::endl;
        return ans;
    }
};

int main(int arg, char *argv[])
{
    string str = "abcabcbb";
    Solution s;
    s.lengthOfLongestSubstring(str);

    return 0;
}