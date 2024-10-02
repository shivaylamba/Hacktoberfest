/*
Given three integers P,R and T, denoting Principal, Rate of Interest and 
Time period respectively.Compute the simple Interest.
Your Task:
You don't need to read input or print anything.
Your Task is to complete the function simpleInterest() 
which takes three integers P,R and T and returns the simple interest.

Expected Time Complexity:O(1)
Expected Auxillary Space:O(1)
 
Constraints:
1<=P<=105
1<=R,T<=100
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    double simpleInterest(int P, int R, int T) {
        // code here
        return (double)(P*R*T)/100 ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int P, R, T;
        cin >> P >> R >> T;
        Solution ob;
        cout << fixed << setprecision(2);
        cout << ob.simpleInterest(P, R, T) << "\n";
    }
}

// } Driver Code Ends