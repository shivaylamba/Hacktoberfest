/*
Recursive sequence
A function F is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... upto n terms (look at the examples for better clarity). Given an integer n, determine the F(n).

Note: As the answer can be very large, return the answer modulo 109+7.

Example 1:

Input: n = 5
Output: 365527
Explanation: 
F(5) = 1 + 2*3 + 4*5*6 + 7*8*9*10 + 11*12*13*14*15 = 365527.
Example 2:

Input: n = 7
Output: 6006997207
Explanation: 
F(7) = 1 + 2*3 + 4*5*6 + 7*8*9*10 + 11*12*13*14*15 + 
16*17*18*19*20*21 + 22*23*24*25*26*27*28 = 6006997207.
6006997207 % 109+7 = 6997165
Your Task:
You do not need to read input or print anything. Your task is to complete the function sequence() which takes an integer n as an input parameter and returns the value of F(n).

Expected Time Complexity: O(n2)
Expected Space Complexity: O(1)

Constraints:
1 ≤ n ≤ 103
*/
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        const int d = 1e9+7;
        // code here
        long long ans = 0;
        long long  count =1;
        for(int i=0;i<n;i++){
            long long ans2 = 1;
            for(int j=0;j<=i;j++){
                 ans2%=d;
                ans2*=count;
                count++;
            }
            ans +=ans2%d;
        }
        return ans%d;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends