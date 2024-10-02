/*
Maximize The Cut Segments
Given an integer n denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum. Return the maximum number of cut segments possible.
Note: if no segment can be cut then return 0.
Examples:
Input: n = 4, x = 2, y = 1, z = 1
Output: 4
Explanation: Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.
Input: n = 5, x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.
Expected Time Complexity : O(n)
Expected Auxiliary Space: O(n)
Constraints
1 <= n, x, y, z <= 104
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution
{
    public:
    int cut(int n, int x, int y, int z,vector<int> &dp){
        //base case
        if(n<0) return INT_MIN;
        else if(n==0) return 0;
        //recursive case
        else if(dp[n]!=0) return dp[n];
        int cutx=cut(n-x,x,y,z,dp);
        int cuty=cut(n-y,x,y,z,dp);
        int cutz=cut(n-z,x,y,z,dp);
        return dp[n]= 1+max(cutx,max(cuty,cutz));
        
        
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,0);
        if(cut(n,x,y,z,dp)<0) return 0;
        return cut(n,x,y,z,dp);
    }
};
//{ Driver Code Starts.
int main() {
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;
    }
	return 0;
}
// } Driver Code Ends