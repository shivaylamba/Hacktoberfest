/*
Given an array Arr of size N, print second largest distinct element from an array.
Your Task:
You don't need to read input or print anything. Your task is to complete the function print2largest() which takes the array of integers arr and n as parameters and returns an integer denoting the answer. If 2nd largest element doesn't exist then return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
2 ≤ N ≤ 105
1 ≤ Arri ≤ 105
*/
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
    int first = INT_MIN, second = -1; 
    for (int i = 0; i < n; i++) { 
          first = max(first,arr[i]);
    }
    for(int i=0;i<n;i++){
        if(arr[i]!=first){
            if(second < arr[i]){
                second =arr[i];
            }
        }
    }
    return second;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends