/*
Write a program to find the sum of the given series 1+2+3+ . . . . . .(N terms) 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	// function to return sum of  1, 2, ... n
	long long seriesSum(int n) {
	    // Methods 1st but O(n) Time Complexity
	 /*
        if(n==0)
	    return 0;
	    else
	    return n + seriesSum(n-1);
     */
    // Methods-2 Time Complexity of O(1) and Space compolexity is O(1)
  if (n % 2 == 0)
      // Here multiplying by 1LL help to 
      // perform calculations in long long, 
      // so that answer should not be overflowed
      return (n / 2) * 1LL * (n + 1); 
   // If n is odd, (n+1) must be even
   else
      // Here multiplying by 1LL help to 
      // perform calculations in long long, 
      // so that answer should not be overflowed
      return  ((n + 1) / 2) * 1LL * n; 
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
        auto ans = ob.seriesSum(n);
        cout << ans << "\n";
    }
    return 0;
}