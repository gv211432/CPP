<!-- ┏━┓╻  ╻   ┏━┓┏┓ ┏━┓╻ ╻╺┳╸ ┏━┓╻ ╻╻┏━╸╻┏ ┏━┓┏━┓┏━┓╺┳╸
     ┣━┫┃  ┃   ┣━┫┣┻┓┃ ┃┃ ┃ ┃  ┃┓┃┃ ┃┃┃  ┣┻┓┗━┓┃ ┃┣┳┛ ┃
     ╹ ╹┗━╸┗━╸ ╹ ╹┗━┛┗━┛┗━┛ ╹  ┗┻┛┗━┛╹┗━╸╹ ╹┗━┛┗━┛╹┗╸ ╹ -->

Iterative Quick Sort

    Difficulty Level : Medium
    Last Updated : 06 Sep, 2021

Following is a typical recursive implementation of Quick Sort that uses last element as pivot.

<!-- ==================================================================== -->

// CPP code for recursive function of Quicksort
#include <bits/stdc++.h>

using namespace std;

// Function to swap numbers
void swap(int* a, int* b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/_ This function takes last element as pivot,
places the pivot element at its correct
position in sorted array, and places
all smaller (smaller than pivot) to left
of pivot and all greater elements to
right of pivot _/
int partition(int arr[], int l, int h)
{
int x = arr[h];
int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);

}

/_ A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index _/
void quickSort(int A[], int l, int h)
{
if (l < h) {
/_ Partitioning index _/
int p = partition(A, l, h);
quickSort(A, l, p - 1);
quickSort(A, p + 1, h);
}
}

// Driver code
int main()
{

    int n = 5;
    int arr[n] = { 4, 2, 6, 9, 2 };

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;

}

<!-- ==================================================================== -->

Output:

2 2 4 6 9

<!-- ==================================================================== -->

The above implementation can be optimized in many ways

1. The above implementation uses the last index as a pivot. This causes worst-case behavior on already sorted arrays, which is a commonly occurring case. The problem can be solved by choosing either a random index for the pivot or choosing the middle index of the partition or choosing the median of the first, middle, and last element of the partition for the pivot. (See this for details)
2. To reduce the recursion depth, recur first for the smaller half of the array, and use a tail call to recurse into the other.
3. Insertion sort works better for small subarrays. Insertion sort can be used for invocations on such small arrays (i.e. where the length is less than a threshold t determined experimentally). For example, this library implementation of Quicksort uses insertion sort below size 7.
   Despite the above optimizations, the function remains recursive and uses function call stack to store intermediate values of l and h. The function call stack stores other bookkeeping information together with parameters. Also, function calls involve overheads like storing activation records of the caller function and then resuming execution.
   The above function can be easily converted to an iterative version with the help of an auxiliary stack. Following is an iterative implementation of the above recursive code.

<!-- ==================================================================== -->

// An iterative implementation of quick sort
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}

/_ This function is same in both iterative and recursive_/
int partition(int arr[], int l, int h)
{
int x = arr[h];
int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);

}

/_ A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index _/
void quickSortIterative(int arr[], int l, int h)
{
// Create an auxiliary stack
int stack[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }

}

// A utility function to print contents of arr
void printArr(int arr[], int n)
{
int i;
for (i = 0; i < n; ++i)
cout << arr[i] << " ";
}

// Driver code
int main()
{
int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 };
int n = sizeof(arr) / sizeof(\*arr);
quickSortIterative(arr, 0, n - 1);
printArr(arr, n);
return 0;
}

// This is code is contributed by rathbhupendra

<!-- ==================================================================== -->

Output:

1 2 2 3 3 3 4 5

<!-- ==================================================================== -->

The above-mentioned optimizations for recursive quicksort can also be applied to the iterative version.

1. Partition process is the same in both recursive and iterative. The same techniques to choose optimal pivot can also be applied to the iterative version.
2. To reduce the stack size, first push the indexes of smaller half.
3. Use insertion sort when the size reduces below an experimentally calculated threshold.
   References:
   http://en.wikipedia.org/wiki/Quicksort
   This article is compiled by Aashish Barnwal and reviewed by GeeksforGeeks team. Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above.
