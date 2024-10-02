/*
Check if the number is Fibonacci
Check if a given number N is the Fibonacci number. 
A Fibonacci number is a number that occurs in the Fibonacci series.
Example 1:
Input:
N = 34
Output:
Yes
Explanation:
34 is one of the numbers 
of the Fibonacci series.
Example 2:
Input:
N = 41
Output:
No
Explanation:
41 is not in the numbers 
of the Fibonacci series.
Your Task:
You don't need to read input or print anything. Your task is to complete the function checkFibonacci() which takes an 
integer N and returns a string "Yes" if it is a Fibonacci number else "No".
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
Constraints:
1 <= N <= 100
*/
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 
// } Driver Code Ends
class Solution{   
public:
    string checkFibonacci(int N){
        // code here 
        int a =0,b=1;
        int c=0;
        while(c<N){
            c=a+b;
            a=b;
            b=c;
        }
        return (c==N)?"Yes":"No";
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
        cin >> N;
        Solution ob;
        cout << ob.checkFibonacci(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends