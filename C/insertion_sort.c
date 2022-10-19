// C program for insertion sort
#include <math.h>
#include <stdio.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    /* Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

/* Driver program to test insertion sort */
int main()
{
  int n;
  printf("Enter the number of elements you want to add in the array:");
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    printf("Enter arr[%d]:", i);
    scanf("%d", &arr[i]);
  }
  insertionSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}
/*
output:
Enter the number of elements you want to add in the array:5
Enter arr[0]:1
Enter arr[1]:8
Enter arr[2]:4
Enter arr[3]:2
Enter arr[4]:10
Sorted array:
1 2 4 8 10*/
