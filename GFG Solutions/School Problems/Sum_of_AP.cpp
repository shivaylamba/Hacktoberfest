/*
Sum of an AP
Given n, a and d as the number of terms, first term and common difference respectively of an Arthimetic Series. Find the sum of the series upto nth term.
Your Task:
You don't need to read or print anything. Your task is to complete the function sum_of_ap() which takes n, a and d as input parameter and returns the sum of the series.

Expected Time Complexity: O(1)
Expected Space Complexity: O(1)
 
Constranits:
1 <= n, a, d <= 100
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution
{
	public:
			int sum_of_ap(int n,int a, int d)
		{
		    // Code here.
		    return (n*(2*a + (n-1)*d))/2 ;
		}
};
//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n, a, d;
    	cin >> n >> a >> d;
    	Solution ob;
    	int ans = ob.sum_of_ap(n, a, d);
    	cout << ans << "\n";
    }
	return 0;
}
// } Driver Code Ends