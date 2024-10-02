/*
Two arrays of size N are called identical arrays if they contain the same elements. The order of elements in both arrays could be different; however, both the arrays must contain same elements. You are given two arrays of size N.

You need to determine if the arrays are identical or not.

Example 1:
 

Input : A[] = {1, 2, 3, 4, 5}, B[] = {3, 4, 1, 2, 5}
Output : 1
Explanation:
Here we can see array A[] = [1, 2, 3, 4, 5] and 
B[] = [3, 4, 1, 2, 5]. If we look both the array then we 
can get that array B is the permutation of A. So, both array
are identical. 
Example 2:

Input : A[] = {1, 2, 4}, B[] = {3, 2, 1} 
Output : 0 
 

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function check() that takes an array (arr), another array (brr), size of both array (n), and return the 1 if both the array are identical else 0. The driver code takes care of the printing.

Expected Time Complexity: O(NLog(N)).
Expected Auxiliary Space: O(1).
 

Constraints:
1 ≤ N ≤ 105
0 ≤ A[i] ≤ 9
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int check(int *a, int *b, int n);


int main() {
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], b[n];
        int i;
        for(i = 0; i < n; i++){
            cin>> a[i];
        }
        for(i = 0; i < n; i++){
            cin>> b[i];
        }
        cout << check(a, b, n) << endl;
        
    }
	return 0;
}
// } Driver Code Ends


int check(int *a, int *b, int n){
    // Complete the function
    sort(a,a+n);
    sort(b,b+n);
    for(int i = 0 ;  i<n;i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}