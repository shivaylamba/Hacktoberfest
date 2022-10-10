
#include <bits/stdc++.h>
using namespace std;

//rearrange the elements to get the actual pivot index
int partition(int arr[], int low, int high, int pivot){
	int PIndex = low;
    
	// Traverse the array from low to high
    for(int i=low;i<=high;i++) {   
        
        // If the current element is smaller than the pivot element
        if(arr[i]<=pivot) {
            // Swap PIndex element with current element.
            swap(arr[PIndex],arr[i]);
            // Increment the pointer.
            PIndex++;
        }
    }
    
    PIndex--;
    
	return PIndex;
}

// We divide the array into two subarrays around 
// the pivot and recursively call for them separately.
void quickSort(int arr[], int low, int high){
	if(low < high) {
	    int pivot = arr[high];
        
            //Rearrange and get the actual pivot index
	    int PIndex = partition(arr, low, high, pivot);
	
            // solve for the left and right subarrays
            quickSort(arr, low, PIndex-1);
            quickSort(arr, PIndex+1, high);
	}
}

int main()
{
	
	int arr[7]={6,3,9,5,2,8,7};
	int n=7;
    
	quickSort(arr, 0 , n-1);
    
	cout<<"The sorted array is: ";
	for( int i = 0 ; i < n; i++){
		cout<< arr[i]<<" ";
	}
	
    return 0;
}
