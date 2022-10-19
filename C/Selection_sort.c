// C program for implementation of selection sort
#include <stdio.h>

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selectionSort(int arr[], int n)
{
  int i, j, min_idx;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < n - 1; i++)
  {
    // Find the minimum element in unsorted array
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;

    // Swap the found minimum element with the first element
    if (min_idx != i)
      swap(&arr[min_idx], &arr[i]);
  }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Driver program to test above functions
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
  selectionSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}
/*
Enter the number of elements you want to add in the array:5
Enter arr[0]:5
Enter arr[1]:9
Enter arr[2]:7
Enter arr[3]:4
Enter arr[4]:2
Sorted array:
2 4 5 7 9
*/
