/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	int n = r - l + 1;
	i = 0; //pointer to L[]
	j = 0; //pointer to R[]
	for(k = 0; k < n; k++){
		if(i == n1){
			arr[k] = R[j++];
			continue;
		}
		else if(j == n2){
			arr[k] = L[i++];
			continue;
		}
		if(L[i]<R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
	}
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 


void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 

	printf("Given array is \n"); 
	printArray(arr, arr_size); 

	mergeSort(arr, 0, arr_size - 1); 

	printf("\nSorted array is \n"); 
	printArray(arr, arr_size); 
	return 0; 
} 
