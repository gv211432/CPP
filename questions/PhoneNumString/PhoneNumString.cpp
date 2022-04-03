// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // utility function implementing backracking
    void solve(int count, string ds, string digits, map<char, string> &keypad, vector<string> &ans)
    {
        // if count of the digits equals to the count, push ds in answer and return
        if (count == digits.size())
        {
            ans.push_back(ds);
            return;
        }

        string str = keypad[digits[count]];
        for (int i = 0; i < str.length(); i++)
        {
            ds += str[i];
            solve(count + 1, ds, digits, keypad, ans);
            ds.pop_back();
        }
    }
    // Letter combinations main function
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;       // stores the answer
        map<char, string> keypad; // stores the map of keypad
        keypad['2'] = "abc";
        keypad['3'] = "def";
        keypad['4'] = "ghi";
        keypad['5'] = "jkl";
        keypad['6'] = "mno";
        keypad['7'] = "pqrs";
        keypad['8'] = "tuv";
        keypad['9'] = "wxyz";
        int count = 0;  // maintains the number of digits passed
        string ds = ""; // this is tmeperory string
        if (digits.size() == 0)
            return ans;
        solve(count, ds, digits, keypad, ans);

        return ans;
    }
};

class Solution2
{
    // Creating the keypad hash map
    std::unordered_map<int, std::vector<std::string>> keyPad{
        {2, {"a", "b", "c"}},
        {3, {"d", "e", "f"}},
        {4, {"g", "h", "i"}},
        {5, {"j", "k", "l"}},
        {6, {"m", "n", "o"}},
        {7, {"p", "q", "r", "s"}},
        {8, {"t", "u", "v"}},
        {9, {"w", "x", "y", "z"}}};

public:
    vector<string> letterCombinations(string digits)
    {
        std::vector<std::string> combos{}; // vecotr to hold the result to return

        if (digits.length() == 0) // if no digit is given
            return combos;
        if (digits.length() == 1) // of only one digit is given
            return keyPad[digits[0] - '0'];

        // Get a count of the number of strings we will make
        int count = keyPad[digits[0] - '0'].size();
        for (int i = 1; i < digits.size(); ++i)
            count *= keyPad[digits[i] - '0'].size();

        // places is a vector that holds index of letter to use for each digit
        // each place counts up and rolls over.
        // e.g. When second letter rolls over, the first letter's index increments, etc.
        std::vector<int> places(digits.length(), 0);
        while (combos.size() < count)
        {
            std::string str;
            for (int i = 0; i < places.size(); ++i)
                str.append(keyPad[digits[i] - '0'][places[i]]);

            combos.push_back(str);
            // count up each position and roll over as the number of letters are used up
            int i = 0;

            do
            {
                ++i;
                places[places.size() - i] += 1;
                places[places.size() - i] %= keyPad[digits[digits.length() - i] - '0'].size();
            } while (places[places.size() - i] == 0 && i < digits.length());
        }

        return combos;
    }
};

int main(int arg, char *argv[])
{
    Solution s;

    std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}