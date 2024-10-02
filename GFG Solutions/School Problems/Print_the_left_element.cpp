/*
Given a array of length N, at each step it is reduced by 1 element. 
In the first step the maximum element would be removed, while in the 
second step minimum element of the remaining array would be removed, 
in the third step again the maximum and so on. Continue this till the array 
contains only 1 element. And find the final element remaining in the array.
Example 1:
Input:
N = 7
A[] = {7, 8, 3, 4, 2, 9, 5}
Ouput:
5
Explanation:
In first step '9' would be removed, in 2nd step
'2' will be removed, in third step '8' will be
removed and so on. So the last remaining
element would be '5'.  
Example 2:
Input:
N = 8
A[] = {8, 1, 2, 9, 4, 3, 7, 5}
Ouput:
4
Your Task:  
You don't need to read input or print anything. Your task is to complete 
the function leftElement() which takes 
the array A[] and its size N as inputs and returns the final remaining element in the array.
Expected Time Complexity: O(NLogN)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ N ≤ 106
1 ≤ Ai ≤ 1000
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int leftElement(int a[], int n) {
        // Your code goes here   
        sort(a,a+n); // sort the array
        int mid = n/2; // find the middle
        return (n%2!=0)?a[mid]:a[mid-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.leftElement(a, n) << endl;
    }
}

// } Driver Code Ends