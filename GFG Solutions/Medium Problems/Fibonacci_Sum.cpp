/*
Fibonacci Sum
Given a number positive number N, find value of f0 + f1 + f2 + . + fN 
where fi indicates ith Fibonacci number.
Remember that f0 = 0, f1 = 1, f2 = 1, f3 = 2, f4 = 3, f5 = 5,
Since the answer can be very large, answer modulo 1000000007 should be returned.
Example 1:
Input:
N = 3
Output:
4
Explanation:
0 + 1 + 1 + 2  = 4
Example 2:
Input :
N = 4
Output :
7
Explanation :
0 + 1 + 1 + 2 + 3 = 7
Your Task:
You don't need to read input or print anything. Your task is to complete the function fibSum() which takes an integer N as input 
parameter and returns the sum of all the Fibonacci number from F0 to FN.
Expected Time Complexity: O(Log N)
Expected Space Complexity: O(1)
Constraints:
1 <= N <= 100000
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int d = 1000000007;
class Solution{
public:
    long long int fibSum(long long int N){
        //code here
        long long int a = 0 , b = 1,c=0;
        long long int sum =a+b;
        for(int i=2;i<=N;i++){
          c=(a%d+b%d)%d;
           sum+=c;
            a=b;
            b=c;
        }
        return sum%d;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends