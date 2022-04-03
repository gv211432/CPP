// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // This solution is in O(n) time complexity
    // When you iterate the Roman No. string form rare side, it is a fact that small Roman character appears before
    // the greater Roman character means it is substracted from the previous one.
    // Eg: IV=5-1=4,  XC=100-10=90, etc.

    int romanToInt(string s)
    {
        // this map stores the value of roman no. in decimal
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        // 'prvNo' stores the value of previous roman no. in decimal
        // 'ansNo' stores the no. to be returned
        int prvNo = 0, ansNo = 0;

        // iterating until 'i' is 1 (iterating form back of 's')
        for (size_t i = s.size(); i > 0; i--)
        {
            // using 'i-1' as index
            // loading the decimal value of roman no. in temp
            int temp = m.find(s[i - 1])->second;
            // if the temp no. is greater or equal to previous no. add it in the result or substract it
            (temp >= prvNo) ? (ansNo += temp) : (ansNo -= temp);
            // update the previous decimal no. with temp
            prvNo = temp;
        }

        return ansNo;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    std::cout << s.romanToInt("XCVII") << std::endl;
    std::cout << s.romanToInt("MCMXCIV") << std::endl;
    // std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}