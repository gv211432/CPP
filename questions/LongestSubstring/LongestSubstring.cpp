// Main file of the Project
// debug this is accepted by leetcode
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    size_t lengthOfLongestSubstring(string s)
    {

        size_t left = 0, right = 0,    // this index will point the start,end position of substring
            ans = 0;                   // this will hold the length of the found sub string
        unordered_map<char, size_t> m; // hashmap<charcter, index of latest occurence of character> with O(1)

        // the substring between the 'left' and 'right' will be the longest
        // substring with length in 'ans'
        for (right = 0; right < s.size(); right++)
        {
            // right is the current index of characters in the string
            // if character is present in the map 'm'
            if (m.find(s[right]) != m.end())
                left = max(m[s[right]] + 1, left);
            m[s[right]] = right + 1;            // updating the latest occurence of the character
            ans = max(ans, (right + 1 - left)); // take the maximum form last substring and current substring
        }
        // for (auto x : m)
        //     std::cout << x.first << " => " << x.second << std::endl;
        // std::cout << ans << std::endl;
        return ans;
    }

    // size_t lengthOfLongestSubstring(string s)
    // {
    //     int left = 0, right = 0, // this index will point the start,end position of substring
    //         ans = 0;             // this will hold the length of the found sub string
    //     vector<int> map(256, -1);

    //     while (right < s.size())
    //     {
    //         if (map[s[right]] != -1)
    //             left = max(map[s[right]] + 1, left);
    //         map[s[right]] = right;
    //         ans = max(right - left + 1, ans);
    //         right++;
    //     }

    //     // for (auto x : m)
    //     //     std::cout << x.first << " => " << x.second << std::endl;
    //     std::cout << ans << std::endl;
    //     return ans;
    // }
};

int main(int arg, char *argv[])
{
    string str = "abcabcbb";
    Solution s;
    s.lengthOfLongestSubstring(str);

    return 0;
}