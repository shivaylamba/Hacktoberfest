/*
Logical Operators
Logical operators are used when we want to check the truth value of certain statements. Logical operators help us in checking multiple statements together for their truthness.

Here we will learn logical operators like AND(&&), OR(||), NOT(!). These operators produce either a true or a false as an output.

Example:

Input:
a = 6
b = 7
Output:1 1 0
Explanation:a && b = 1
a || b = 1
(!a) && (!b) = 0
Your Task:
Your task is to complete the provided function.

Constraints:
1 <= a, b,<= 100
*/
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

void logicOp(int a, int b);


// } Driver Code Ends
//User function Template for C++


void logicOp(int a, int b)
{
    /*output (a&&b), (a||b), and ((!a)&&(!b))separated by spaces*/ 
    cout<<(a && b)<<" "<< (a || b)<<" "<< (!a && !b) <<endl;
}

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int a,b;
	    cin>>a>>b;
	    logicOp(a,b);
	    
	}
	return 0;
}
// } Driver Code Ends