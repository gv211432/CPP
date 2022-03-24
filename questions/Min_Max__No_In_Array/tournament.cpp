#include <iostream>
using namespace std;

// Making struct for the pair of the numbers..
struct minMaxPair
{
    int minimum;
    int maximum;
};

// the following function is implemented in that way it can be called recursively..
// ================================================================
struct minMaxPair findMinMax(int array[], int low = 0, int high = 0)
{
    struct minMaxPair pairOfNumber, pairsOfLeft, pairsOfRight;
    int mid = 0;

    // If there is only one element
    if (low == high)
    {
        pairOfNumber.minimum = pairOfNumber.maximum = array[low];
        return pairOfNumber;
    }

    // If there are two numbers then
    if (high == low + 1)
    {
        if (array[low] > array[high])
        {
            pairOfNumber.maximum = array[low];
            pairOfNumber.minimum = array[high];
        }
        else
        {
            pairOfNumber.maximum = array[high];
            pairOfNumber.minimum = array[low];
        }
        return pairOfNumber;
    };

    // If the program still continues then there are numbers more than 2
    mid = (low + high) / 2;
    pairsOfLeft = findMinMax(array, low, mid);
    pairsOfRight = findMinMax(array, mid + 1, high);

    //----------------------------------------------------------------
    if (pairsOfRight.minimum > pairsOfLeft.minimum)
    {
        pairOfNumber.minimum = pairsOfLeft.minimum;
    }
    else
    {
        pairOfNumber.minimum = pairsOfRight.minimum;
    }

    //----------------------------------------------------------------
    if (pairsOfRight.maximum > pairsOfLeft.maximum)
    {
        pairOfNumber.maximum = pairsOfRight.maximum;
    }
    else
    {
        pairOfNumber.maximum = pairsOfLeft.maximum;
    }

    return pairOfNumber;
};

// ----------------------------------------------------------------
int main(int argc, char *argv[])
{

    if (argc == 0)
    {
        cout << "No arguments were given!!!";
        return 0;
    };

    int myArr[20];

    // first argument contains the name of the program ignoring that
    for (size_t i = 0; i < argc - 1; i++)
    {
        // Assigning the initial value rather than leaving to assing memory with garbage value..
        myArr[i] = 0;
        myArr[i] = atoi(argv[i + 1]);
        // cout << myArr[i] << "\n";
    };

    // int myArr[] = {23, 56, 4, 50, 78, 9, 3};

    struct minMaxPair myNums = findMinMax(myArr, 0, (argc - 2));

    cout << "\n"
         << "The Maximum number amongst the number is " << myNums.maximum << " and minimum is " << myNums.minimum << "\n\n";

    return 0;
};