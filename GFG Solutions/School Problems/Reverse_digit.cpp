/*
Given N,  reverse the digits of N.
Your Task:
You don't need to read or print anything. Your task is to complete the function reverse_digit() which takes N as input parameter and returns the reversed number.
 
Expected Time Complexity: O(Log(N))
Expected Space Complexity: O(1)
 
Constraints:
1 <= N <= 1015
*/
//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution
{
	public:
		long long int reverse_digit(long long int n)
		{
		    long long int ans=0;
		    // Code here
		    while(n>0){
		        long long int ld = n%10;
		        ans=ans*10 + ld;
		        n/=10;
		    }
		    return ans;
		}
};
//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int n;
    	cin >> n;
    	Solution ob;
    	long long int  ans = ob.reverse_digit(n);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends