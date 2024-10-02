/*
Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.

Note: If at any instance, there are no more subarrays of size greater than or equal to K, then reverse the last subarray (irrespective of its size). You shouldn't return any array, modify the given array in-place.
Your Task:
You don't need to read input or print anything. The task is to complete the function reverseInGroups() which takes the array, N and K as input parameters and modifies the array in-place. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N, K ≤ 107
1 ≤ A[i] ≤ 1018
*/
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function template for C++
class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
       
    for (int i = 0; i < n; i += k)
    {
        int left = i;
 
        // to handle case when k is not multiple of n
        int right = min(i + k - 1, n - 1);
 
        // reverse the sub-array [left, right]
        while (left < right)
            swap(arr[left++], arr[right--]);
 
    }
    }
};