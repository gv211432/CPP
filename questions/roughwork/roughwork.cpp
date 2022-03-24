// Main file of the Project
#include <iostream>
#include <cmath>

using namespace std;

int main(int arg, char *argv[])
{
    int x = -2147483648;

    if ((x >= 0 && (x > (INT32_MAX / 10))) || (x >= 0 && (x > (INT32_MAX - 10))))
        return 0;

    int num = x;

    int reverseNo = 0;
    while (num)
    {
        int n = num - (num / 10) * 10;
        reverseNo = reverseNo * 10 + n, num = num / 10;
    }

    std::cout << reverseNo << std::endl;
    return reverseNo;
}