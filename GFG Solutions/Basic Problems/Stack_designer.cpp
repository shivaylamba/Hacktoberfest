/*
Stack designer
You are given an array arr of size N. You need to push the elements of the array into a stack and then print them while popping.

Example 1:

Input:
n = 5
arr = {1 2 3 4 5}
Output:
5 4 3 2 1
Example 2: 

Input: 
n = 7
arr = {1 6 43 1 2 0 5}
Output: 
5 0 2 1 43 6 1
 

Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided functions _push() and _pop().

Constraints:
1 <= Ai <= 107
*/
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

stack<int>_push(int arr[],int n);


void _pop(stack<int>s);


// } Driver Code Ends
//User function Template for C++

/* _push function to insert elements of array to
   stack
*/
stack<int>_push(int arr[],int n)
{
   //return a stack with all elements of arr inserted in it
   stack<int> st;
   for(int i=0;i<n;i++){
       st.push(arr[i]);
   }
   return st;
}

/* _pop function to print elements of the stack
   remove as well
*/
void _pop(stack<int> s)
{
    //print top and pop for each element until it becomes empty
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _pop(mys);
	    cout<<endl;
	    
	    
	    
	}
	return 0;
}


// } Driver Code Ends