/*
Given a string, remove spaces from it. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function modify() which takes the string S as input and returns the resultant string by removing all the white spaces from S.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1<=|S|<=105
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution
{
  public:
    string modify (string s)
    {
        //code here.
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                s.erase(i,1);
                i--;
            }
        }
        return s;
    }
};
//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        string s;
        getline (cin, s);
        Solution ob;
        cout <<ob.modify (s) << endl;
    }
    return 0;
}
// Contributed By: Pranay Bansal
// } Driver Code Ends