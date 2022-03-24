// Main file of the Project
#include <bits/stdc++.h>
// Time Complexity: O(n2) as there are two nested loops.
// Auxiliary Space: O(1)
// The good thing about selection sort is it never makes more than O(n)
// swaps and can be useful when memory write is a costly operation.

// this it the swap function to swap data of two memory location
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// this is the selection swap function which sorts the given array in O(n2)
void SelectionSort(int arr[], int n)
{
    int i, j, min_i;

    for (i = 0; i < n - 1; i++)
    {
        min_i = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_i])
                min_i = j;
        }
        swap(&arr[min_i], &arr[i]);
    }
}

// print the given array
void PrintArr(int arr[], int n)
{
    std::cout << std::endl;

    int totalChar = 0;
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
        totalChar += std::to_string(arr[i]).length();
        // std::cout << std::to_string(arr[i]).length() << std::endl;
    }
    std::cout << std::endl;

    // std::cout << totalChar << std::endl;

    for (int i = 0; i < totalChar; i++)
    {
        std::cout << "=";
    }
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << "=";
    }

    std::cout << std::endl;
}

int main(int arg, char *argv[])
{
    int nums[arg - 1];
    for (int i = 0; i < arg - 1; i++)
    {
        nums[i] = atoi(argv[i + 1]);
    }

    // for (int i = 0; i < arg - 1; i++)
    // {
    //     std::cout << nums[i] << std::endl;
    // }

    PrintArr(nums, arg - 1);
    SelectionSort(nums, arg - 1);
    PrintArr(nums, arg - 1);

    // std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}