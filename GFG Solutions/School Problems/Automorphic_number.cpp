/*
Given a number N, check whether the number is Automorphic number or not.
A number is called Automorphic number if and only if its square ends in  has the same last digit as the number itself.
Your Task:
You don't need to read or print anything. Your task is to complete the function is_AutomorphicNumber() which takes n as input parameter and returns "Automorphic" if it is Automorphic number otherwise returns "Not Automorphic"(Without quotes).
Expected Time complexity: O(log(N))
Expected Space Complexity: O(1)
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
		string is_AutomorphicNumber(int n)
		{
		    // Code here
		    int ld1 = n%10;
		    int number = pow(n,2);
		    int ld2 = number%10;
		    return (ld1 == ld2)?"Automorphic":"Not Automorphic";
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_AutomorphicNumber(n);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends