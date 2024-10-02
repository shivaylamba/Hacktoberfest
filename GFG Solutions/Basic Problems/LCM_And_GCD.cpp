/*
Given two numbers A and B. The task is to find out their LCM and GCD.
Example 1:
Input:
A = 5 , B = 10
Output:
10 5
Explanation:
LCM of 5 and 10 is 10, while
thier GCD is 5.
Example 2:
Input:
A = 14 , B = 8
Output:
56 2
Explanation:
LCM of 14 and 8 is 56, while
thier GCD is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete 
the function lcmAndGcd() which takes an Integer N as input and returns a List of two Integers, the required LCM and GCD.
Expected Time Complexity: O(log(min(A, B))
Expected Auxiliary Space: O(1)
Constraints:
1 <= A,B <= 1018
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution {
  public:
  long long gcd(long long a,long long b){
      if(a==0){return b;}
        if(b==0){return a;}
        while(a!=b){
            if(a>b){
                a-=b;
            }
            else{
                b-=a;
            }
        }
        return a;
  }
    vector<long long> lcmAndGcd(long long a , long long b) {
        // code here
        return {(a/gcd(a,b))*b , gcd(a,b)};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends