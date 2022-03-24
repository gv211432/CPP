// Main file of the Project
#include <iostream>
using namespace std;

// // This will divide the given array in two sub arrays,
// // then it will merge those arrya in one array, in ascending order.
// void merge(int arr[], int const left, int const mid, int const right)
// {
//     // defining length of the sub arrays
//     auto const leftSubArrLen = mid - left + 1;
//     auto const rightSubArrLen = right - mid;

//     // this will dinamically allocate the memory for temperory arrays and later unallocate it
//     auto *leftSubArr = new int[leftSubArrLen], *rightSubArr = new int[rightSubArrLen];

//     // dumping the array data in the temperary left-sub-array and right-sub-array
//     // this will copy the array data in two small arrays
//     for (auto i = 0; i < leftSubArrLen; i++)
//         leftSubArr[i] = arr[left + i];

//     for (auto j = 0; j < rightSubArrLen; j++)
//         rightSubArr[j] = arr[mid + 1 + j];

//     // initial index of the left-sub-array and right-sub-array before starting merger
//     auto indexLeftSubArr = 0, indexRightSubArr = 0;

//     // index of the merged array
//     auto indexMergeArr = left;

//     // Merging the left-sub-array and right-sub-array and overwritting the actual array
//     while (indexLeftSubArr < leftSubArrLen && indexRightSubArr < rightSubArrLen)
//     {
//         if (leftSubArr[indexLeftSubArr] <= rightSubArr[indexRightSubArr])
//         {
//             arr[indexMergeArr] = leftSubArr[indexLeftSubArr];
//             indexLeftSubArr++;
//         }
//         else
//         {
//             arr[indexMergeArr] = rightSubArr[indexRightSubArr];
//             indexRightSubArr++;
//         }
//         indexMergeArr++;
//     }

//     // copying the remaining left-sub-array elements in the array, if any
//     while (indexLeftSubArr < leftSubArrLen)
//     {
//         arr[indexMergeArr] = leftSubArr[indexLeftSubArr];
//         indexLeftSubArr++;
//         indexMergeArr++;
//     }

//     // copying the remaining right-sub-array elements in the array, if any
//     while (indexRightSubArr < rightSubArrLen)
//     {
//         arr[indexMergeArr] = rightSubArr[indexRightSubArr];
//         indexRightSubArr++;
//         indexMergeArr++;
//     }
// }

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
    auto const leftSubArrLen = mid - left + 1;
    auto const rightSubArrLen = right - mid;

    // Create temp arrays
    auto *leftArray = new int[leftSubArrLen],
         *rightArray = new int[rightSubArrLen];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < leftSubArrLen; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < rightSubArrLen; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexLeftSubArr = 0,      // Initial index of first sub-array
        indexRightSubArr = 0;      // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexLeftSubArr < leftSubArrLen && indexRightSubArr < rightSubArrLen)
    {
        if (leftArray[indexLeftSubArr] <= rightArray[indexRightSubArr])
        {
            array[indexOfMergedArray] = leftArray[indexLeftSubArr];
            indexLeftSubArr++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexRightSubArr];
            indexRightSubArr++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexLeftSubArr < leftSubArrLen)
    {
        array[indexOfMergedArray] = leftArray[indexLeftSubArr];
        indexLeftSubArr++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexRightSubArr < rightSubArrLen)
    {
        array[indexOfMergedArray] = rightArray[indexRightSubArr];
        indexRightSubArr++;
        indexOfMergedArray++;
    }

    delete leftArray;
    delete rightArray;
}

void mergeSort(int arr[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;

    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, begin, mid, end);
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

    std::cout << arg - 1 << std::endl;
    PrintArr(nums, arg - 1);
    mergeSort(nums, 0, arg - 1);
    PrintArr(nums, arg - 1);

    // std::cout << "Hello " << argv[0] << " project" << std::endl;
    return 0;
}