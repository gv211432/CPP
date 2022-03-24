//Main file of the Project
#include <bits/stdc++.h>
#define min(l, r) ((l > r) ? r : l)

int BinarySearch(int arr[], int, int, int);
int ExponentialSearch(int arr[], int arrLen, int);

int BinarySearch(int arr[], int low, int high, int num)
{
    // execute following until low index does not cross high index
    if (high >= low)
    {
        // finding the middle element's index
        // low plus half of the difference of the low and high
        int mid = low + (high - low) / 2;

        // if element equals to the number
        if (arr[mid] == num)
            return num;

        // if middel element is less than the number
        if (arr[mid] > num)
            return BinarySearch(arr, low, mid - 1, num);

        // if the middle element is greater than the number
        return BinarySearch(arr, mid + 1, high, num);
    }
    return -1;
}

int ExponentialSearch(int arr[], int arrLen, int num)
{
    // if number is equals to the first element of the array
    if (num == arr[0])
        return 0;

    int index = 1;

    // loop until index is smaller than array length and
    // encountered number is greater than required number
    while (index < arrLen && num >= arr[index])
        index *= 2;

    // index may have crossed the required element in last interation
    // hence divide by 2 to get previous index
    // also upperbound must be the minimum of inder or array length
    return BinarySearch(arr, index / 2, min(index, arrLen - 1), num);
};

int main(int arg, char *argv[])
{
    int arr[] = {10, 20, 40, 45, 55, 80, 120, 145, 223, 456, 789, 999};
    int arrSize = sizeof(arr) / sizeof(int);
    // std::cout << "Size of array : " << sizeof(arr) / sizeof(int) << std::endl;
    // std::cout << "Your array is : [" << std::endl;

    std::cout << ExponentialSearch(arr, arrSize, 120) << std::endl;
    // std::cout << min(45, 80) << std::endl;

    return 0;
}