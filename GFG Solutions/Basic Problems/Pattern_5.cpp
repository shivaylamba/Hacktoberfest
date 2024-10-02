/*
Geek is very fond of patterns. Once, his teacher gave him a pattern to solve.
He gave Geek an integer n and asked him to build a pattern.
Help Geek build a star pattern.
Example 1:
Input: 5
Output:
* * * * *
* * * * 
* * * 
* *  
* 
Your Task:
You don't need to input anything. 
Complete the function printTriangle() which takes  an integer n  as 
the input parameter and print the pattern.
Constraints:
1<= N <= 20
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution{
public:
	
	void printTriangle(int n) {
	    // code here
	    for(int i=n;i>=1;i--){
	        for(int j = 1;j<=i;j++){
	            cout<<"*"<<" ";
	        }
	        cout<<endl;
	    }
	}
};
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends