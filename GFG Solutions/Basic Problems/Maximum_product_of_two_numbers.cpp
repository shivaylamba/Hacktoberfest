/*
Given an array Arr of size N with all elements greater than or equal to zero. Return the maximum product of two numbers possible.

Example 1:

Input: 
N = 6
Arr[] = {1, 4, 3, 6, 7, 0}  
Output: 42
Example 2:

Input: 
N = 5
Arr = {1, 100, 42, 4, 23}
Output: 4200
Your Task:  
You don't need to read input or print anything. Your task is to complete the function maxProduct() which takes the array of integers arr[] and n as parameters and returns an integer denoting the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ N ≤ 107
0 ≤ Arr[i] ≤ 104
*/
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:

	int maxProduct(int arr[], int n) {
	    // code here
	    // Time Complexity O(n*log(n))
	    // space Complexity O(1)
	   // sort(arr,arr+n);
	   // return arr[n-1]*arr[n-2];
	   
	   // Time Complexity O(n)
	   // space Complexity O(1)
	   int max1 = INT_MIN , max2=INT_MIN;
	   for(int i=0;i<n;i++){
	       max1=max(max1,arr[i]);
	   }
	   int count =0;
	   for(int i=0;i<n;i++){
	       if(arr[i]==max1){
                count++;
                if(count>1){
                    max2=max1;
                    break;
                }
	       }
	       else{
	           max2 = max(max2,arr[i]);
	       }
	   }
	   return max1*max2;
	   
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends