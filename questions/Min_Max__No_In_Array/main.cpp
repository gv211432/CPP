// ┏┳┓╻┏┓╻   ┏┳┓┏━┓╻ ╻   ┏┓╻┏━┓   ╻┏┓╻   ┏━┓┏━┓┏━┓┏━┓╻ ╻
// ┃┃┃┃┃┗┫   ┃┃┃┣━┫┏╋┛   ┃┗┫┃ ┃   ┃┃┗┫   ┣━┫┣┳┛┣┳┛┣━┫┗┳┛
// ╹ ╹╹╹ ╹╺━╸╹ ╹╹ ╹╹ ╹╺━╸╹ ╹┗━┛╺━╸╹╹ ╹╺━╸╹ ╹╹┗╸╹┗╸╹ ╹ ╹

#include <iostream>
using namespace std;

// Used to get values in pair..
struct minMaxPair
{
    int min;
    int max;
};

// Function to calculate min and max form the given array with its length..
// =====================================================================
struct minMaxPair findMinMax(int arr[], int arrLength)
{
    // minMax will hold the values of the minimum and maximun of the array..
    struct minMaxPair minMax;
    int i;
    // If the lenght is 1 means the smallest and the largest number is the only
    // number present in the loop...
    if (arrLength == 1)
    {
        minMax.min = arr[0];
        minMax.max = arr[0];
    }
    if (arr[1] > arr[0])
    {
        minMax.min = arr[0];
        minMax.max = arr[1];
    }
    else
    {
        minMax.min = arr[1];
        minMax.max = arr[0];
    }

    // If length is greater the 2 means 3 or more elements in the array
    // Then check the element with the current stored number in the pair
    // and if the number is larger than the stored one just replace with it or
    // if not then check it with the smalles one and replace on success!!!
    for (size_t i = 2; i < arrLength; i++)
    {
        if (arr[i] > minMax.max)
        {
            minMax.max = arr[i];
        }
        else if (arr[i] < minMax.min)
        {
            minMax.min = arr[i];
        }
    }

    return minMax;
};

// =====================================================================
int main(int argc, char *argv[])
{
    // int numArr[] = {3, 5, 47, 90, 87, 4};

    if (argc == 0)
    {
        cout << "No arguments were given!!!";
        return 0;
    };

    int myArr[20];

    // first argument contains the name of the program ignoring that
    for (int i = 0; i < argc - 1; i++)
    {
        // Assigning the initial value rather than leaving to assing memory with garbage value..
        myArr[i] = 0;
        myArr[i] = atoi(argv[i + 1]);
        // cout << myArr[i] << "\n";
    };

    // This will generate the minimum and maximum value form the given array by user..
    struct minMaxPair myPair = findMinMax(myArr, (argc - 1));

    cout << "The max number is " << myPair.max << " and minimum number is " << myPair.min << "\n";
    return 0;
};