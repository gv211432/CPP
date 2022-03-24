#include <bits/stdc++.h>

// this search alog creates two mid points in the given range and recurse
int TernarySearch(int arr[], int low, int high, int num)
{
    // if low index does not cross high index
    if (high >= low)
    {
        // creating two middle index
        int midLow = low + (high - low) / 3;
        int midHigh = midLow + (high - low) / 3;

        // if the midLow index contains required number
        if (arr[midLow] == num)
            return midLow;

        // if the midHigh index contains the required number
        if (arr[midHigh] == num)
            return midHigh;

        // if the number is smaller than middleLow element
        if (num < arr[midLow])
            return TernarySearch(arr, low, midLow - 1, num);

        // it the middle High element is less than the required number
        if (arr[midHigh] < num)
            return TernarySearch(arr, midHigh + 1, high, num);

        // if the required number is in between the midLow and midHigh
        return TernarySearch(arr, midLow + 1, midHigh - 1, num);
    }
    return -1;
}

int main(int arg, char *argv[])
{
    int arr[] = {1, 5, 8, 10, 12, 20, 25, 30, 35, 40, 45, 70, 90, 100, 140, 150, 180, 200};
    int low = 0;
    int high = sizeof(arr) / sizeof(int);

    std::cout << TernarySearch(arr, low, high, 30) << std::endl;

    // std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}