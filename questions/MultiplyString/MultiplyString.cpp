// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

// // Reference
// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         if (num1 == "0" || num2 == "0") {
//             return "0";
//         }

//         // Reverse num1 and num2.
//         reverse(num1.begin(), num1.end());
//         reverse(num2.begin(), num2.end());

//         // Initialize answer as a string of zeros of length N.
//         int N = num1.size() + num2.size();
//         string answer(N, '0');

//         for (int place2 = 0; place2 < num2.size(); place2++) {
//             int digit2 = num2[place2] - '0';

//             // For each digit in num2 multiply the digit by all digits in num1.
//             for (int place1 = 0; place1 < num1.size(); place1++) {
//                 int digit1 = num1[place1] - '0';

//                 // The number of zeros from multiplying to digits depends on the
//                 // place of digit2 in num2 and the place of the digit1 in num1.
//                 int numZeros = place1 + place2;

//                 // The digit currently at position numZeros in the answer string
//                 // is carried over and summed with the current result.
//                 int carry = answer[numZeros] - '0';
//                 int multiplication = digit1 * digit2 + carry;

//                 // Set the ones place of the multiplication result.
//                 answer[numZeros] = (multiplication % 10) + '0';

//                 // Carry the tens place of the multiplication result by
//                 // adding it to the next position in the answer array.
//                 answer[numZeros + 1] += (multiplication / 10);
//             }
//         }

//         if (answer.back() == '0') {
//             answer.pop_back();
//         }
//         reverse(answer.begin(), answer.end());
//         return answer;
//     }
// };

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        // reverse the numbers
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int N = num1.size() + num2.size();
        string answer(N, '0');

        for (size_t place2 = 0; place2 < num2.size(); place2++)
        {
            int digit2 = num2[place2] - '0';
            for (size_t place1 = 0; place1 < num1.size(); place1++)
            {
                int digit1 = num1[place1] - '0';
                int num_zero = place1 + place2;
                int carry = answer[num_zero] - '0';
                int multiplication = digit1 * digit2 + carry;
                answer[num_zero] = (multiplication % 10) + '0';
                answer[num_zero + 1] += (multiplication / 10);
            }
        }
        if (answer.back() == '0')
            answer.pop_back();
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

int main(int arg, char *argv[])
{
    string n1 = argv[1], n2 = argv[2];
    Solution s;
    std::cout << "Product of " << n1 << " and " << n2 << " is : " << s.multiply(n1, n2) << std::endl;
    return 0;
}