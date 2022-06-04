// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string Hasher(array<uint8_t, 26> &a)
    {
        string hash_code = "";
        for (auto n : a)
            hash_code.append(to_string(n));
        return hash_code;
    }

    void PrintArr(array<uint8_t, 26> &a, string color = "0")
    {
        std::cout << "\033[" << color << "marray[ ";
        for (auto &n : a)
            std::cout << to_string(n), (&n == &a.back()) ? std::cout << " " : std::cout << ", ";
        std::cout << "]\033[0m" << std::endl;
    }

public:
    vector<int> findAnagrams(string s, string p)
    {
        array<uint8_t, 26> arr = {0};

        for (auto l : p)
            arr[l - 'a']++;

        string hash_code = Hasher(arr), tmp_hash;

        std::cout << "\033[34m"
                  << "Hash code : " << hash_code << "\033[0m" << std::endl;

        for (auto l : p)
            arr[l - 'a'] = 0;

        std::cout << "should be empty : " << std::endl;
        PrintArr(arr, "32");

        std::cout << "hash code : " << hash_code << std::endl;
        for (size_t i = 0; i < p.size() - 1; i++)
            arr[s[i] - 'a']++;

        std::cout << "First filled : " << std::endl;
        PrintArr(arr, "33");

        s = "o" + s; // padding the string "s" by one character
        vector<int> ans = {};
        for (size_t i = p.size(); i <= s.size(); i++)
        {
            std::cout << "For index : " << i - p.size() << std::endl;

            if (arr[s[i - p.size()] - 'a'] > 0)
                arr[s[i - p.size()] - 'a']--;

            arr[s[i] - 'a']++;
            PrintArr(arr, "31");
            tmp_hash = Hasher(arr);
            (tmp_hash == hash_code) ? cout << "True\n" : cout << "False\n";
            if (tmp_hash == hash_code)
                ans.push_back(i - p.size());
        }
        return ans;
    }
};

// Accepted by leetcode
class Solution2
{
    string Hasher(uint8_t *a)
    {
        string hash_code = "";
        for (size_t i = 0; i < 26; i++)
            hash_code.append(to_string(*(a + i)));
        return hash_code;
    }

public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans = {};
        if (s.size() < p.size())
            return ans;

        uint8_t arr[26] = {};
        for (size_t i = 0; i < 26; i++)
            arr[i] = 0;

        for (auto l : p)
            arr[l - 'a']++;

        string hash_code = Hasher(arr), tmp_hash;

        // std::cout << "\033[31m"
        //           << "Hasher Code : " << hash_code << "\033[0m" << std::endl;

        for (auto l : p)
            arr[l - 'a'] = 0;

        for (size_t i = 0; i < p.size(); i++)
            arr[s[i] - 'a']++;

        // s = "o" + s; // padding the string "s" by one character
        for (size_t i = p.size() + 1; i < s.size(); i++)
        {
            size_t index = i - p.size();
            if (arr[s[index] - 'a'] > 0)
                arr[s[index] - 'a']--;
            arr[s[i] - 'a']++;
            tmp_hash = Hasher(arr);
            if (tmp_hash == hash_code)
                ans.push_back(index);
        }
        return ans;
    }
};

// fastest
class Solution3
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans; // to hold the answer
        array<uint8_t, 26> hash = {0};
        array<uint8_t, 26> phash = {0};

        int window = p.size();
        int len = s.size();
        if (len < window)
            return ans;

        int left = 0, right = 0;
        while (right < window)
        {
            phash[p[right] - 'a'] += 1;
            hash[s[right] - 'a'] += 1;
            right++;
        }
        right -= 1;
        while (right < len)
        {
            if (phash == hash)       // if both array is same then
                ans.push_back(left); // add the current index in the list of answers

            right += 1;
            if (right != len)
                hash[s[right] - 'a'] += 1;
            hash[s[left] - 'a'] -= 1;
            left += 1;
        }
        return ans;
    }
};
int main(int arg, char *argv[])
{
    Solution3 s;

    // for (auto n : s.findAnagrams("cbaebabacd", "abc"))
    //     std::cout << "Index : " << n << std::endl;

    // for (auto n : s.findAnagrams("baa", "aa"))
    //     std::cout << "Index : " << n << std::endl;

    for (auto n : s.findAnagrams("vqmdnixkslfhotuwzcbaypejgrvqmdnixkslfhotuwzcbayp", "hotuwzcbaypejgr"))
        std::cout << n << ",  ";
    std::cout << std::endl;

    return 0;
}