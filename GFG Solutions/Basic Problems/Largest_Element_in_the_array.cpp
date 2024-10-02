/*
Largest ELement in the Array Your Task:  
You don't need to read input or print anything. Your task is to complete the function largest() which takes the array A[] and 
its size n as inputs and returns the maximum element in the array.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
1 <= n<= 103
0 <= A[i] <= 103

*/
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        for(int i=1;i<n;i++){
            arr[0] = max(arr[0],arr[i]);
        }
        return arr[0];
    }
};
//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.largest(arr, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends