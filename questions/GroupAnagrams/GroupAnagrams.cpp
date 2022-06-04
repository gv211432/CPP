// Main file of the Project
#include <bits/stdc++.h>
#include "../utilities/utilities.h"
using namespace std;

// This is reference form the leetcode user
class SolutionRef
{
public:
    // this utility overloads the () operator how to be used by the unordered_map
    struct ArrayHasher
    {
        size_t operator()(const std::array<uint8_t, 26> &a) const
        {
            std::size_t h{};
            for (auto e : a)
                h ^= std::hash<int>{}(e) + 0x9e3779b9 + (h << 6) + (h >> 2); // debug Less knowledge about this but working fine
            return h;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        array<uint8_t, 26> key; // to hold the characters 'a' at 0 and 'z' at 25th index

        // creating hash map to store the string with anagram in corresponding bucket
        // this bucket will be int (ie. sum of all ascii characters in perticular string)
        unordered_map<array<uint8_t, 26>, vector<string>, ArrayHasher> map;
        for (const auto &str : strs)
        {
            key = {}; // cleans the key array for new usage
            for (auto c : str)
                key[c - 'a']++;      // feeding the characters from one of the given strings to key array
            map[key].push_back(str); // pushing this above array in map, this will be first analyzed by the ArrayHasher function
        }

        vector<vector<string>> ans; // to store the answer
        ans.reserve(map.size());
        for (auto &kv : map)
            ans.push_back(std::move(kv.second));
        // move first 4 element from vec1 to starting position of vec2
        // std ::move(vec1.begin(), vec1.begin() + 4, vec2.begin() + 1);

        return ans;
    }
};

class Solution
{
    // struct array_hasher
    // {
    //     size_t operator()(const array<uint8_t, 26> &a) const
    //     {
    //         size_t h{};
    //         for (auto e : a)
    //             h ^= hash<int>{}(e) + 0x9e3779b9 + (h << 6) + (h >> 2);
    //         return h;
    //     }
    // };

public:
    // vector<vector<string>> groupAnagrams(vector<string> &strs)
    // {
    //     vector<vector<string>> ans = {}; // this is answer variable
    //     // if (strs[0] == "")
    //     //     return ans;

    //     // array<uint8_t, 26> key_hash = {};
    //     // creating hash map to store the string with anagram in corresponding bucket
    //     // this bucket will be int (ie. sum of all ascii characters in perticular string)
    //     unordered_map<int, vector<string>> hash_map = {};
    //     // unordered_map<array<uint8_t, 26>, vector<string>, array_hasher> hash_map = {};

    //     // traversing through all stings
    //     for (auto &s : strs)
    //     {
    //         std::cout << "str : " << s << std::endl;
    //         int hash_num = 0;
    //         if (s == "")
    //             hash_num = -1;
    //         else
    //             array={},
    //             for (auto c : s) // adding all the ascii characters to hash_num
    //                 hash_num += hash(c);

    //         if (hash_map.count(hash_num) > 0) // if some elements present in anangram group, just push one more
    //             hash_map.find(hash_num)->second.push_back(s);
    //         else // creating new vector to push ananram group strings
    //         {
    //             vector<string> v = {s};
    //             hash_map.emplace(make_pair(hash_num, v));
    //         }
    //     }

    //     // ans.pop_back();
    //     for (auto &h : hash_map) // push all present anagram groups in ans
    //         ans.push_back(h.second);

    //     print_v::print_vov(ans);
    //     return ans;
    // }

    int hash_me(string &s)
    {
        size_t h = 0;
        unordered_map<char, int> map = {};
        for (const auto &c : s)
            if (map.count(c) > 0)
                map[c]++;
            else
                map.emplace(make_pair(c, 1));

        for (auto m : map)
            h += pow(m.first - '0', m.second);

        return h;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans = {}; // this is answer variable

        unordered_map<char, uint8_t> alpha = {{'a', 109}, {'b', 131}, {'c', 137}, {'d', 173}, {'e', 11}, {'f', 13}, {'g', 17}, {'h', 19}, {'i', 23}, {'j', 31}, {'k', 37}, {'l', 43}, {'m', 47}, {'n', 53}, {'o', 57}, {'p', 59}, {'q', 61}, {'r', 67}, {'s', 71}, {'t', 73}, {'u', 79}, {'v', 83}, {'w', 91}, {'x', 89}, {'y', 97}, {'z', 103}};
        unordered_map<size_t, vector<string>> hash_map = {};

        for (auto &s : strs)
        {
            // size_t hash_num = hash_str(s);
            size_t hash_num = 0;
            for (auto c : s)
                hash_num += alpha[c];

            if (hash_map.count(hash_num) > 0) // if some elements present in anangram group, just push one more
                hash_map[hash_num].push_back(s);
            else // creating new vector to push ananram group strings
            {
                vector<string> v = {s};
                hash_map.emplace(make_pair(hash_num, v));
            }
        }

        // ans.pop_back();
        for (auto &h : hash_map) // push all present anagram groups in ans
            ans.push_back(h.second);

        print_v::print_vov(ans);
        return ans;
    }
};

int main(int arg, char *argv[])
{
    SolutionRef s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat", "", ""};
    // vector<string> strs = {"", ""};
    s.groupAnagrams(strs);
    // int c = ''

    // hash<string> hash_str;
    // string boy = "";
    // size_t h = hash_str(boy);

    // std::cout << h << std::endl;
    return 0;
}