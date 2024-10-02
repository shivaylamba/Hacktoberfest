/*
Given an array Arr of size N, swap the Kth element from beginning with Kth element from end.
Your Task:
You don't need to read input or print anything. Your task is to complete the function swapKth() which takes the array of integers arr, n and k as parameters and returns void. You have to modify the array itself.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ K ≤ N ≤ 105
1 ≤ Arr[i] ≤ 103
*/
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    bool IsPerfect(int a[],int n)
    {
        // Complete the function
        int flag=0;
   for(int i=0;i<n;i++){
       if(a[i]==a[n-i-1]){
           flag=1;
       }
       else{
           flag=0;
           break;
       }
   }
   return (flag==1)?1:0;
    }
};
//{ Driver Code Starts.
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        if(ob.IsPerfect(a,n))
            cout<<"PERFECT\n";
        else
            cout<<"NOT PERFECT\n";
    }
    
}
// } Driver Code Ends