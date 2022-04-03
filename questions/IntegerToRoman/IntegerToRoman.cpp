// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void intToRoman(int num)
    {
        if (num > 999999)
            std::cout << "Maximum value reached" << std::endl;
        int copy = num;

        string romanMap[7][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                                  {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                                  {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                                  {"", "M", "MM", "MMM", "MV", "V", "VM", "VMM", "VMMM", "MX"},
                                  {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                                  {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                                  {"", "M", "MM", "MMM", "MV", "V", "VM", "VMM", "VMMM", "MX"}};

        string ans = "";
        string bar = "";

        int i = 0;
        while (num)
        {
            int units = num % 10;
            ans = romanMap[i][units] + ans;
            int j = romanMap[i][units].size();
            while (j)
            {
                j--;
                if (i >= 3)
                {
                    char c = (romanMap[i][units])[j];
                    if (c == 'V' || c == 'X' || c == 'L' || c == 'D' || c == 'C')
                        bar = "_" + bar;
                    else if (i > 4 && c == 'M')
                        bar = "_" + bar;
                    else
                        bar = " " + bar;
                }
                else
                {
                    bar = " " + bar;
                }
            }

            i++;
            num /= 10;
        }
        std::cout << bar << std::endl;
        std::cout << ans << " Is Roman Number of : " << copy << std::endl;
    }
};

class Solution2 // works for 3999
{
public:
    string intToRoman(int num)
    {
        string ans;
        while (num)
        {
            if (num >= 1000)
                ans += 'M', num -= 1000;
            else if (num >= 900)
                ans += "CM", num -= 900;
            else if (num >= 500)
                ans += 'D', num -= 500;
            else if (num >= 400)
                ans += "CD", num -= 400;
            else if (num >= 100)
                ans += 'C', num -= 100;
            else if (num >= 90)
                ans += "XC", num -= 90;
            else if (num >= 50)
                ans += 'L', num -= 50;
            else if (num >= 40)
                ans += "XL", num -= 40;
            else if (num >= 10)
                ans += 'X', num -= 10;
            else if (num >= 9)
                ans += "IX", num -= 9;
            else if (num >= 5)
                ans += 'V', num -= 5;
            else if (num >= 4)
                ans += "IV", num -= 4;
            else
                ans += 'I', num--;
        }
        return ans;
    }
};

class Solution3 // works for 3999
{
public:
    string intToRoman(int num)
    {
        int number[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string sign[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string sb;

        for (int i = 0; i < (sizeof(number) / sizeof(number[0])) && num > 0; i++)
        {
            while (number[i] <= num)
            {
                num = num - number[i];
                sb.append(sign[i]);
            }
        }
        return sb;
    }
};

int main(int arg, char *argv[])
{
    Solution2 s;
    // s.intToRoman(999999);
    std::cout << s.intToRoman(3478) << std::endl;
    return 0;
}