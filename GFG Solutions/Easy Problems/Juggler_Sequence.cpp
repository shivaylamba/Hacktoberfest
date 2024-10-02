/*
Juggler Sequence
Juggler Sequence is a series of integers in which the first term starts with a positive integer number a and the remaining terms are generated from the immediate previous term using the below recurrence relation:
Juggler Formula
Given a number n, find the Juggler Sequence for this number as the first term of the sequence until it becomes 1.
Example 1:
Input: n = 9
Output: 9 27 140 11 36 6 2 1
Explaination: We start with 9 and use 
above formula to get next terms.
Example 2:
Input: n = 6
Output: 6 2 1
Explaination: 
[61/2] = 2. 
[21/2] = 1.

Your Task:
You do not need to read input or print anything. Your Task is to complete the function jugglerSequence() which takes n as the input parameter and returns a list of integers denoting the generated sequence.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
   void solve(long long n ,vector<long long>&ans){
       long long int a = n;
       if(n==1) return ;
       
       if(n&1){
           a = floor(sqrt(n)*sqrt(n)*sqrt(n));
       }
       else{
           a = sqrt(n);
       }
       ans.push_back(a);
       solve(a,ans);
   }
  public:
    vector<long long> jugglerSequence(long long n) {
        // code here
        vector<long long > ans;
        ans.push_back(n);
        if(n==1) return{1};
        solve(n,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends