/*
Given a stream of incoming numbers, find average or mean of the stream at every point.

 

Example 1:

Input:
n = 5
arr[] = {10, 20, 30, 40, 50}
Output: 10.00 15.00 20.00 25.00 30.00 
Explanation: 
10 / 1 = 10.00
(10 + 20) / 2 = 15.00
(10 + 20 + 30) / 3 = 20.00
And so on.
 

Example 2:

Input:
n = 2
arr[] = {12, 2}
Output: 12.00 7.00 
Explanation: 
12 / 1 = 12.00
(12 + 2) / 2 = 7.00
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function streamAvg() which takes the array of integers arr and n as input parameters and returns an array of type float denoting the average at every point in the stream. 

 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

 

Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 106
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:	
	vector<float> streamAvg(int arr[], int n) {
	    // code here
	    vector<float> ans;
	    float sum = 0 ;
	    for(int i = 0 ; i<n;i++){
	        sum+=arr[i];
	        ans.push_back(sum/(i+1));
	    }
	    return ans;
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
        auto ans = ob.streamAvg(arr, n);
        cout << fixed<< setprecision(2);
        for (auto x : ans) {
            cout <<x<<" ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends