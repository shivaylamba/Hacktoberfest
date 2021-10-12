#include <iostream>

using namespace std; 

 // A recursive binary search function. It returns location of x in given array arr[l..r] is present, 
// otherwise -1  

int binarySearch(int arr[], int first, int last, int x) { 

    if (last >= first) { 
        int mid = (last + first) / 2; 

        if (arr[mid] == x) return mid; 

        if (arr[mid] > x) 
            return binarySearch(arr, first, mid - 1, x);  
        return binarySearch(arr, mid + 1,last, x); 
    } 
    return -1; 
} 

  
int main() { 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int x;
    cin >> x;
    
    int n = sizeof(arr) / sizeof(arr[0]); 

    int result = binarySearch(arr,0,n - 1, x); 

    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result; 
    return 0; 
} 
