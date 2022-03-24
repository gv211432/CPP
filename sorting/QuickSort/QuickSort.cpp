// Main file of the Project
#include <iostream>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
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
    // int nums[arg - 1];

    // for (int i = 0; i < arg - 1; i++)
    // {
    //     nums[i] = atoi(argv[i + 1]);
    // }

    int nums[] = {78, 90, 67, 90, 63, 2, 1, 35};

    // std::cout << arg - 1 << std::endl;
    PrintArr(nums, 8);
    QuickSort(nums, 0, 8);
    PrintArr(nums, 8);

    // std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}