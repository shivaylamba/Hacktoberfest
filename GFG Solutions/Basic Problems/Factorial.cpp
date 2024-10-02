/*
Given a positive integer, N. Find the factorial of N.
Example 1:
Input:
N = 5
Output:
120
Explanation:
5*4*3*2*1 = 120
Example 2:
Input:
N = 4
Output:
24
Explanation:
4*3*2*1 = 24
Your Task:
You don't need to read input or print anything. Your task is to complete the function factorial()
 which takes an integer N as input parameters and returns an integer, the factorial of N.

Expected Time Complexity: O(N)
Expected Space Complexity: O(1)

Constraints:
0 <= N <= 18
*/
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int factorial(int n){
        //code here
        long long int n1 = n;
        if(n1==0){
            return 1;
        }
        else{
            return n1*factorial(n1-1);
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.factorial(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends