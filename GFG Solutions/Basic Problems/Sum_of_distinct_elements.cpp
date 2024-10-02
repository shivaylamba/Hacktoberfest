/*
Sum of distinct elements
You are given an array Arr of size N. Find the sum of distinct elements in an array.

Example 1:

Input:
N = 5
Arr[] = {1, 2, 3, 4, 5}
Output: 15
Explanation: Distinct elements are 1, 2, 3
4, 5. So sum is 15.
Example 2:

Input:
N = 5
Arr[] = {5, 5, 5, 5, 5}
Output: 5
Explanation: Only Distinct element is 5.
So sum is 5.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findSum() which takes the array of integers arr and n as parameters and returns an integer denoting the answer.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(N*logN)

Constraints:
1 ≤ N ≤ 107
0 ≤ A[i] ≤ 104
*/
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Find the sum of all non-repeated elements
	// in an array
// Using the Set 
// Time Complexity O(n)
// Space Complexity O(n)
	int findSum(int arr[], int n) {
	    // code here
	set<int> s;
	for(int i=0;i<n;i++){
	    s.insert(arr[i]);
	}
	int sum = 0;
	for(auto i:s){
	    sum+=i;
	    }
	    return sum;
	}
// Using the Sorting Techniques
// Time Complexity O(n* log(n))
// Space Complexity O(1)
    	int findSum(int arr[], int n) {
	    // code here
        sort(arr,arr+n);
        int sum = 0;
        for(int i=0;i<n;i++){
            if(arr[i-1]!=arr[i]){
                sum+=arr[i];
            }
        }
	    return sum;
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
        auto ans = ob.findSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends