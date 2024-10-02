/*
Given a string S as input. Delete the characters at odd indices of the string.
Your Task:  
You dont need to read input or print anything. Complete the function delAlternate() which takes S as input parameter and returns the final string after deletion of characters at odd indices.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string delAlternate(string S) {
        // code here
        for(int i=1;i<S.size();i++){
            S.erase(i,1);
        }
        return S;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.delAlternate(S) << endl;
    }
    return 0;
}

// } Driver Code Ends