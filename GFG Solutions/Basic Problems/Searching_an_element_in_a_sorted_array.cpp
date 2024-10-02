/*
Searching an element in a sorted array
Given an array arr[] sorted in ascending order of size N and an integer K. Check if K is present in the array or not.
our Task:
You don't need to read input or print anything. Complete the function searchInSorted() which takes the sorted array arr[], its size N and the element K as input parameters and returns 1 if K is present in the array, else it returns -1. 
Expected Time Complexity: O(Log N)
Expected Auxiliary Space: O(1)
Constraints:
1 <= N <= 106
1 <= K <= 106
1 <= arr[i] <= 106
*/
//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int N, int K) 
    { 
       int i=0 , j = N-1;
       int mid = i + (j-i)/2;
       while(i<=j){
           if(arr[mid] == K){
               return 1;
           }
           else if(arr[mid]<K){
               i =mid+1;
           }
           else{
               j =mid-1;
           }
           mid = i + (j-i)/2;
       }
       return -1;
       // Your code here
       
    }
};

//{ Driver Code Starts.


int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;

    }

	return 0; 
} 

// } Driver Code Ends