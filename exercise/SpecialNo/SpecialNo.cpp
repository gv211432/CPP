#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    // feeding the quartic values
    int quartic[10] = {0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561};

    list<int> isPresent;

    int len = 0;
    std::cin >> len;

    // taking the given numbers in an array
    for (int i = 0; i < len; i++)
    {
        int num = 0;
        cin >> num;

        int totalCount = 0;
        for (int j = 1; j <= num; j++)
        {
            if (isPresent.back() < j)
            {

                int addedQu = 0;
                int mulDigit = 1;

                int lendIt = j;

                while (lendIt > 0)
                {
                    int digit = lendIt % 10;
                    lendIt /= 10;
                    addedQu += quartic[digit];
                    mulDigit *= digit;
                }

                if (gcd(addedQu, mulDigit) > 1)
                {
                    totalCount += 1;
                    isPresent.push_back(j);
                }
            }
            else
            {
                auto it = std::find(isPresent.begin(), isPresent.end(), j);
                if (it != isPresent.end())
                {
                    totalCount += 1;
                }
            }
        }
        std::cout << totalCount << std::endl;
    }

    return 0;
}