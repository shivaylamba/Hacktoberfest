/*
Given a string S. The task is to convert characters of string to lowercase.
Your Task:  
You dont need to read input or print anything. Complete the function toLower() which takes S as input parameter and returns the converted string.

Expected Time Complexity:O(n)
Expected Auxiliary Space: O(1) 

Constraints:
1 <= |S| <= 1000
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string toLower(string S) {
        // code here
        int i=0;
        while(i<S.size()){
            if(S[i]>='A' && S[i]<='Z'){
                S[i] =S[i] - 'A' + 'a';
            }
           i++;
        }
        return S;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.toLower(S) << endl;
    }
    return 0;
}

// } Driver Code Ends