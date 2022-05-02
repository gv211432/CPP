// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string ans = "1";
        for (int i = 2; i <= n; i++)
        {
            string temp = "";
            for (int j = 0; ans[j]; j++)
            {
                int count = 1;
                while (ans[j] && ans[j] == ans[j + 1])
                    j++, count++;
                temp = temp + to_string(count) + ans[j];
            }
            ans = temp;
        }
        // std::cout << "Answer : " << ans << std::endl;
        return ans;
    }
};

class Solution2
{
public:
    string countAndSay(int n)
    {
        // base case
        if (n == 1)
            return "1";

        string s = countAndSay(n - 1);

        // return say s
        string out;
        int i = 0, count = 1;
        while (i < s.size())
        {
            while (i + 1 < s.size() && s[i] == s[i + 1])
                i++, count++;

            out += to_string(count) + s[i];
            count = 1, i++;
        }
        return out;
    }
};

int main(int arg, char *argv[])
{
    // int n = 4;
    Solution2 s;
    // s.countAndSay(4);
    // s.countAndSay(5);
    // s.countAndSay(6);
    // s.countAndSay(10);
    // std::cout << "Count and Say of " << n << " : " << s.countAndSay(n) << std::endl;

    std::cout << s.countAndSay(20) << std::endl;
    return 0;
}