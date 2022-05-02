// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> map = {{')', '('}, {']', '['}, {'}', '{'}};
        for (size_t i = 0; s[i]; i++)
        {
            if (s[i] == '(' or s[i] == '{' or s[i] == '[')
                std::cout << "Pushing in stack : " << s[i] << std::endl, st.push(s[i]);
            else
            {
                if (st.empty())
                    return false;
                char c = st.top();
                st.pop();
                std::cout << "Stack char removal : " << c << std::endl;
                if (map[s[i]] == c)
                    continue;
                return false;
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};

class Solution2
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> u = {{')', '('}, {']', '['}, {'}', '{'}};

        // if current char matchs with the opposite char of its, pop the stack or else push in the stack
        for (int i = 0; s[i]; i++)
            (!st.empty() && u[s[i]] == st.top()) ? st.pop() : st.push(s[i]);

        // if stack is not empty means some pairs are not stisfied
        return (st.empty()) ? true : false;
    }
};

int main(int arg, char *argv[])
{
    Solution2 s;

    std::cout << "Value of given string is : \n"
              << s.isValid("]") << std::endl;
    return 0;
}