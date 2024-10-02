//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    bool isVowel(char c){
          return (c=='a' || c=='A' || c=='e' ||
            c=='E' || c=='i' || c=='I' ||
            c=='o' || c=='O' || c=='u' ||
            c=='U');
    }
        string modify (string s)
        {
            //code here.
            int i=0 , j = s.size()-1;
            while(i<j){
                if(!isVowel(s[i])){
                    i++;
                }
                else if(!isVowel(s[j])){
                    j--;
                }
                else{
                    swap(s[i],s[j]);
                    i++;j--;
                }
            }
            return s;
            
        }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.modify (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends