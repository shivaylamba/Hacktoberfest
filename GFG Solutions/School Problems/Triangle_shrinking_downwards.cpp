/*
Given a string of a constant length, print a triangle out of it. The triangle should start with the given string and keeps shrinking downwards by removing one character from the begining of the string. The spaces on the left side of the triangle should be replaced with dot character.

 

Example 1:

Input:
S = Geeks
Output:
Geeks
.eeks
..eks
...ks
....s
Example 2:

Input:
S = @io30 
Output:
 @io30
.io30
..o30
...30
....0 
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function triDownwards() which takes a String S and returns a string formed by joining all the lines together. For the Input "GEEKS" you should return the String "GEEKS.EEKS..EKS...KS....S".
Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(|S|)

Constraints:
1 <= |S| <=100
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
#include<string>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string triDownwards(string s) {
        // code here
        string ans = s;
        int i = 0 , j = s.size();
        while(i<j-1){
            s[i++]='.';
            ans+=s;
        }
        return ans;
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
        string ans=ob.triDownwards(S);
        
        for(int i=0 ; i<ans.length() ; i++)
        {
            cout<<ans[i];
            if((i+1)%S.length()==0)
                cout<<endl;
        }
        
    }
    return 0;
}
// } Driver Code Ends