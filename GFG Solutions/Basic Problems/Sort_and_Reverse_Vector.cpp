/*
Sort and Reverse Vector
You are given a vector V of size n. You need to sort it and reverse it.
Example 1:
Input:
n = 5
V = 1 2 3 4 5
Output: 
1 2 3 4 5
5 4 3 2 1
Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided 
functions sortVector() and reverseVector(). Return the vector after performing suitable operations.
Constraints:
1 <= n <= 107
0 <= Vi <= 107
*/
//{ Driver Code Starts
//Initial Template for C++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> sortVector(vector<int>v);
vector<int> reverseVector(vector<int>v);
// } Driver Code Ends
//User function Template for C++
vector<int> sortVector(vector<int>v)
{
   //Your code here. Use library function
   sort(v.begin(),v.end());
    return v;
}
vector<int> reverseVector(vector<int>v)
{
     //Your code here. Use library function
    reverse(v.begin(),v.end());
    return v;
}
//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>v;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        v.push_back(x); //Input vector elements
	    }
	    
	    v=sortVector(v); //sort and store in v
	   
	   for(auto x:v)
	   cout<<x<<" "; //print elements of v
	   cout<<endl; 
	   v=reverseVector(v); //reverse v and store it in v
	   for(auto x:v)
	   cout<<x<<" "; //print elements of v
	   cout<<endl;
	   
	}
	return 0;
}
// } Driver Code Ends