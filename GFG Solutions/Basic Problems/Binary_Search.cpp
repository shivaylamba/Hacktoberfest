/*
Given a sorted array of size N and an integer K, find the position(0-based indexing) at which K is present in the array using binary search.
Your Task:  
You dont need to read input or print anything. Complete the function binarysearch() which takes arr[], N and K as input parameters and returns the index of K in the array. If K is not present in the array, return -1.

Expected Time Complexity: O(LogN)
Expected Auxiliary Space: O(LogN) if solving recursively and O(1) otherwise.

Constraints:

1 <= N <= 105
1 <= arr[i] <= 106
1 <= K <= 106
*/
//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
       int st =0 , en = n-1;
       int mid = (st+en)/2;
        while(st<=en){
            if(arr[mid]==k){
                return mid;
            }
            else if(arr[mid]<k){
                st = mid + 1;
            }
            else{
                en =mid - 1;
            }
             mid = (st+en)/2; 
        }
        return -1;
    }
};
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}
// } Driver Code Ends