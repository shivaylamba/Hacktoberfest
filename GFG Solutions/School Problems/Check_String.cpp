/*
Given a string, check if all its characters are the same or not.

Example 1:

Input:
s = "geeks"
Output: False
Explanation: The string contains different
character 'g', 'e', 'k' and 's'.

Example 2:

Input: 
s = "gggg"
Output: True
Explanation: The string contains only one
character 'g'.

Your Task:
You don't need to read input or print anything. Your task is to complete the function check() which takes a string as input and returns True if all the characters in the string are the same. Else, it returns False.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        bool check (string s)
        {
        	//code here.
        	for(int i=0;i<s.size()-1;i++){
        	    if(s[i]!=s[i+1]){
        	        return 0;
        	    }
        	}
        	return 1;
        }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
		string s;
		cin >> s;
		Solution ob;
		if (ob.check (s))
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends