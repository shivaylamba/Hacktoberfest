/*
Given an integer, check whether it is a palindrome or not.
Your Task:
You don't need to read or print anything. Your task is to complete the function is_palindrome() which takes the number as input parameter and returns "Yes" if it is palindrome otherwise returns "No"(Without quotes).
 
Expected Time Complexity: O(x)
Expected Space Complexity: O(x) where x is number of digits in n.
 
Constraints:
1 <= n <= 1000
*/
//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++
class Solution
{
	public:
		string is_palindrome(int n)
		{
		    // Code here.
		 int ans =0;
        int element = n;
        while(element >0){
            int ld = element%10;
            ans = ans*10 + ld;
            element/=10;
        }
        return (ans == n)?"Yes":"No";
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
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends