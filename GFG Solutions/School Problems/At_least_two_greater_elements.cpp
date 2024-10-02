/*
Given an array of N distinct elements, the task is to find all elements in array except two greatest elements in sorted order.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function findElements() which takes the array A[] and its size N as inputs and return the vector sorted values denoting the elements in array which have at-least two greater elements than themselves.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)

Constraints:
3 ≤ N ≤ 105
-106 ≤ Ai ≤ 106
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution{
public:
    vector<int> findElements(int a[], int n)
    {
        vector<int> ans;
        // Your code goes here   
        sort(a,a+n);
        for(int i =0;i<(n-2);i++){
            ans.push_back(a[i]);
        }
        return ans;
    }
};
//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        Solution ob;
        vector <int> res = ob.findElements(a,n);
        
        for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
        cout<<endl;
    }
}
// } Driver Code Ends