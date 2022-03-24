// Main file of the Project
#include <iostream>

int countMinimumMoves(int arr[], int n, int k)
{
    int i;

    // Check if it is possible or not
    // That is if all the elements from
    // index K to N are not equal
    for (i = k - 1; i < n; i++)
        if (arr[i] != arr[k - 1])
            return -1;

    // Find minimum number of moves
    for (i = k - 1; i >= 0; i--)
        if (arr[i] != arr[k - 1])
            return i + 1;

    // Elements are already equal
    return 0;
}

int main(int arg, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 56};
    int K = 5;

    int n = sizeof(arr) / sizeof(arr[0]);

    // std::cout << countMinimumMoves(arr, n, K);

    printf("%d\n", countMinimumMoves(arr, n, K));

    return 0;
}