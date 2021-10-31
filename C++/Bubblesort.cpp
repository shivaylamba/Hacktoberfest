//Cpp program for bubble sort.

//Header files
#include <bits/stdc++.h>
using namespace std;



//Swapping the elements.
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


//Implementation for bubble sort.
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)	
	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
}


//Printng the array.
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}



//Main function
int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

	bubbleSort(arr, n);
	cout<<"Sorted array: \n";

	printArray(arr, n);
	return 0;
}

/* 
Input
Enter the number of elements: 6
Enter the elements: 78 65 34 80 12 19

*/

/*  
Output
Sorted array:
12 19 34 65 78 80

*/
