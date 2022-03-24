// Main file of the Project
//  #include <iostream>
#include <bits/stdc++.h>

// Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
// Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
// Auxiliary Space: O(1)
// Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
// Sorting In Place: Yes
// Stable: Yes

// this function swaps the data of given two memory loctions
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// This is the main Bubble Sort function for sorting
void BubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = false;

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

// This function prints the given array elements and underlines it
void PrintArr(int arr[], int n)
{
    int totalChar = 0;

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
        totalChar += std::to_string(arr[i]).length();
    }

    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << "=";
    }
    for (int i = 0; i < totalChar - 1; i++)
    {
        std::cout << "=";
    }

    std::cout << std::endl;
}

int main(int arg, char *argv[])
{
    int nums[arg - 1];
    for (int i = 1; i < arg; i++)
    {
        nums[i - 1] = atoi(argv[i]);
    }

    PrintArr(nums, arg - 1);

    BubbleSort(nums, arg - 1);

    PrintArr(nums, arg - 1);

    return 0;
}