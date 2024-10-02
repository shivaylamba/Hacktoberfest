/*
Given two positive integers A and B, find GCD of A and B.
Your Task:  
You don't need to read input or print anything. Complete the function gcd() which takes two positive integers as input parameters and returns an integer.

Expected Time Complexity: O(log(min(A, B)))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ A, B ≤ 109
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++
class Solution
{
	public:
    int gcd(int A, int B) 
	{ 
	    // code here
	      return __gcd(A,B);
	} 
};
//{ Driver Code Starts.
int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends