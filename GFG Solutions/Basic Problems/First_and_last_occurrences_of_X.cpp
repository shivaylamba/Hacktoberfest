/*
Given a sorted array having N elements, find the indices of the first 
and last occurrences of an element X in the given array.
Note: If the number X is not found in the array, return '-1' as an array.
Example 1:
Input:
N = 4 , X = 3
arr[] = { 1, 3, 3, 4 }
Output:
1 2
Explanation:
For the above array, first occurence
of X = 3 is at index = 1 and last
occurence is at index = 2.
Example 2:
Input:
N = 4, X = 5
arr[] = { 1, 2, 3, 4 }
Output:
-1
Explanation: 
As 5 is not present in the array,
so the answer is -1.
Your Task:
You don't need to read input or print anything. Complete the function firstAndLast() that takes the array arr, its size N and the value X as input 
parameters and returns a list of integers containing the indices of first and last occurence of X.
Expected Time Complexity: O(log(N))
Expected Auxiliary Space: O(1)
Constraints: 
1 <= N <= 10^5 
0 <= arr[i], X <= 109
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution {
  public:
  int firstPosition(vector<int> &arr, int n, int x){
      int st =0 , en =n-1;
      int ans =-1;
      int mid = st+(en-st)/2;
      while(st<=en){
          if(arr[mid]==x){ ans =mid; en =mid-1;}
          else if(arr[mid]>x){ en =mid-1; }
          else if(arr[mid]<x){ st = mid+1;}
          mid = st + (en -st)/2;
      }
      return ans;
  }
   int lastPosition(vector<int> &arr, int n, int x){
         int st =0 , en =n-1;
      int ans =-1;
      int mid = st+(en-st)/2;
      while(st<=en){
          if(arr[mid]==x){ ans =mid; st =mid+1;}
          else if(arr[mid]>x){ en =mid-1; }
          else if(arr[mid]<x){ st = mid+1;}
          mid = st + (en -st)/2;
      }
      return ans;
  }
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        if(firstPosition(arr,n,x)==-1 && lastPosition(arr,n,x)==-1) return {-1};
        return {firstPosition(arr,n,x),lastPosition(arr,n,x)};
    }
};
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends