#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15

// Merge two sorted subarrays `arr[low … mid]` and `arr[mid+1 … high]`
void Merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;

    // while there are elements in the left and right runs
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
        }
    }

    // copy remaining elements
    while (i <= mid) {
        aux[k++] = arr[i++];
    }

    // copy back to the original array
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
}

// Sort array `arr[low…high]` using auxiliary array `aux`
void mergesort(int arr[], int aux[], int low, int high)
{
    // base case
    if (high <= low) {        // if run size <= 1
        return;
    }

    // find midpoint
    int mid = (low + ((high - low) >> 1));

    // recursively split runs into two halves until run size <= 1,
    // then merge them and return up the call chain

    mergesort(arr, aux, low, mid);          // split/merge left half
    mergesort(arr, aux, mid + 1, high);     // split/merge right half

    Merge(arr, aux, low, mid, high);        // merge the two half runs.
}

// Function to check if arr is sorted in ascending order or not
int isSorted(int arr[])
{
    int prev = arr[0];
    for (int i = 1; i < N; i++)
    {
        if (prev > arr[i])
        {
            printf("MergeSort Failed!!");
            return 0;
        }
        prev = arr[i];
    }

    return 1;
}

int main(void)
{
    int arr[N], aux[N];
    srand(time(NULL));

    // generate random input of integers
    for (int i = 0; i < N; i++) {
        aux[i] = arr[i] = (rand() % 100) - 50;
    }

    // sort array `arr` using auxiliary array `aux`
    mergesort(arr, aux, 0, N - 1);

    if (isSorted(arr))
    {
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
