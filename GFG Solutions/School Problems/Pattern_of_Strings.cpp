/*
Given a string S of length N, find the pattern of the strings as shown below in the examples.

Example 1:

Input: S = "GeeK"
Output: Geek
        Gee
        Ge
        G
Explanation: Decrease one character 
after each line
â€‹Example 2:

Input: S = "G*g" 
Output: G*g
        G*
        G
Explanation: Decrease one character
after each line
Your Task:  
You don't need to read input or print anything. Your task is to complete the function pattern() which takes the string S as inputs and returns the answer as a list of strings.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ N ≤ 103
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	vector<string> pattern(string S)
	{
	    // Your code goes here
	    vector<string> ans;
	    int i = 0  , j  = S.size();
	    if(j==1){
	        return {S};
	    }
	   while(i!=j){
	       string str  = S.substr(i,j);
	       ans.push_back(str);
	       j--;
	   }
	   return ans;
	}

};

//{ Driver Code Starts.

int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   		Solution ob;

   		vector<string> ans = ob.pattern(s);

   		for(int i = 0; i < ans.size(); i++)
   			cout << ans[i] << "\n";
   		
   	}

    return 0;
}
// } Driver Code Ends