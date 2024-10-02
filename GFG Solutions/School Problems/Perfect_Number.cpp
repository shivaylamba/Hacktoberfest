/*
Given a number N. Check if it is perfect or not.
 A number is perfect if sum of factorial of its digit is equal to the given number.
Your Task:
You don't need to read input or print anything.Your task is to complete the function isPerfect() which takes a number N as input parameter and returns 1 if N is perfect.Otherwise, it returns 0.

Expected Time Complexity: O(Log10N)
Expected Auxillary Space: O(constant)

Constraints:
1<=N<=109
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   int factorial( int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
    int isPerfect(int N) {
        // code here
        int ans =0;
        int N1 = N;
      while(N1>0){
          int ld = N1%10;
          ans += factorial(ld);
          N1/=10;
      }
      if(ans == N){
          return 1;
      }
      return 0;
        
    }
};
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isPerfect(N) << "\n";
    }
}
// } Driver Code Ends