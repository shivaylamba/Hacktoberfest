//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int nthTermOfAP(int A1, int A2, int N) {
        // code here
        return (A1 + (N-1)*(A2-A1));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int A1, A2, N;
        cin >> A1 >> A2 >> N;
        Solution ob;
        cout << ob.nthTermOfAP(A1, A2, N) << "\n";
    }
}

// } Driver Code Ends