/*
You are given a string s. You need to reverse the string.
Your Task:

You only need to complete the function reverseWord() that takes s as parameter and returns the reversed string.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 <= |s| <= 10000
*/
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
 int i=0 , j = str.length()-1;
 while(i<=j){
     swap(str[i],str[j]);
     i++;j--;
 }
 return str;
    }
};
//{ Driver Code Starts.
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}