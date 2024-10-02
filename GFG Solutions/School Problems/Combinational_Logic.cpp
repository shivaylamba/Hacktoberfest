/*
Construct a 6 input gate which performs the following logical operation:
 (not(A)).B + C.D +E.(not(F))
where A, B, C, D, E and F are the inputs to the 6 input gate.

Example 1:

Input: A = 1, B = 1, C = 0
       D = 0, E = 1, F = 1
Output: 0 
Explanation: (not(A)).B + C.D +E.(not(F))
= (not(1)).1 + 0.0 +1.(not(1)) = 0.
Example 2:

Input: A = 1, B = 1, C = 1
       D = 1, E = 1, F = 1
Output: 1
Explanation: (not(A)).B + C.D +E.(not(F))
= (not(1)).1 + 1.1 +1.(not(1)) = 1.
Your Task:  
You dont need to read input or print anything. Complete the function logicalOperation() which takes A, B, C, D, E, F as input parameter and returns the result after executing the given opearation.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
0 <= A,B,C,D,E,F <= 1
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int logicalOperation(int A,int B,int C,int D,int E,int F){
        // code here
        return ((~A)&B | C&D | E&(~F));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int A, B, C, D, E, F;
        cin >> A >> B >> C >> D >> E >> F;
        Solution ob;
        cout << ob.logicalOperation(A, B, C, D, E, F) << endl;
    }
    return 0;
}

// } Driver Code Ends