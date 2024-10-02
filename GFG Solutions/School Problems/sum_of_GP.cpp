/*
Given n, a and r as the number of terms, first term and common ratio respectively of an Geometric Progression Series. Find the sum of the series upto nth term
Your Task:
You don't need to read or print anything. Your task is to complete the function sum_of_gp() which takes n, a and r as input parameter and returns the sum of the series.
 
Expected Time Complexity: O(1)
Expected Space Complexity: O(1)
 
Constranits:
1 <= n, a, r <= 10
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long sum_of_gp(long n,long a, long r)
		{
		    // Code here
		    if(r!=1){
		        return (a*(pow(r,n)-1))/(r-1);
		    }
		    else{
		        return a*n ;
		    }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long n, a, r;
    	cin >> n >> a >> r;
    	Solution ob;
    	long long int ans = ob.sum_of_gp(n, a, r);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends