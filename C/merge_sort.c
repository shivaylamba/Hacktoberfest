// author: Akshat Khatri
// date: 26-07-2023
// implementing merge sort algorithm

#include <stdio.h>
#include <stdlib.h>

// Function to print the elements of an array
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to merge two subarrays into a single sorted array
void merge(int arr[], int low, int mid, int high)
{
    int i = low;     // Initial index of the first subarray
    int j = mid + 1; // Initial index of the second subarray
    int k = low;     // Initial index of the merged subarray

    int b[high - low + 1]; // Temporary array to store merged elements

    // Merge the two subarrays in sorted order
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of the first subarray, if any
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the second subarray, if any
    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    // Copy the merged elements back to the original array
    for (int p = low; p <= high; p++)
    {
        arr[p] = b[p - low];
    }
}

// Recursive function to perform merge sort on the array
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Calculate the middle index
        int m = l + (r - l) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Driver code
int main()
{
    int arr[] = {12432, 1143, 1354, 5534, 65, 77};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    // Perform merge sort on the array
    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    return 0;
}
