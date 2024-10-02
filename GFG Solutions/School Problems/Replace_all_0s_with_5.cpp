/*
Given a number N. The task is to complete the function convertFive() which replaces all zeros in the number with 5 and returns the number.

Example:

Input
2
1004
121

Output
1554
121

Explanation:
Testcase 1:  At index 1 and 2 there is 0 so we replace it with 5.
Testcase 2: There is no,0 so output will remain the same.
Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow.
Each test case contains a single integer N denoting the number.

Output:
The function will return an integer where all zero's are converted to 5.

Your Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function convertFive().

Constraints:
1 <= T <= 103
1 <= N <= 104
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
// Driver program to test above function

// } Driver Code Ends
class Solution{
  public:
    /*you are required to complete this method*/
    int convertFive(int n)
    {
    //Your code here
    string n1 = to_string(n);
    for(int i = 0 ; i<n1.size();i++){
        if(n1[i]=='0'){
            n1[i]='5';
        }
    }
    int n2 = stoi(n1);
    return n2;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	Solution obj;
    	cout<<obj.convertFive(n)<<endl;
    }
}
// } Driver Code Ends