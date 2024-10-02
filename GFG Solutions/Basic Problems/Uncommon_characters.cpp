/*
Given two strings A and B consisting of lowercase english characters. Find the characters that are not common in the two strings. 

Note :- Return the string in sorted order.

Example 1:

Input:
A = geeksforgeeks
B = geeksquiz
Output: fioqruz
Explanation: 
The characters 'f', 'i', 'o', 'q', 'r', 'u','z' 
are either present in A or B, but not in both.
Example 2:

Input:
A = characters
B = alphabets
Output: bclpr
Explanation: The characters 'b','c','l','p','r' 
are either present in A or B, but not in both.

Your Task:  
You dont need to read input or print anything. Complete the function UncommonChars() which takes strings A and B as input parameters and returns a string that contains all the uncommon characters in sorted order. If no such character exists return "-1".


Expected Time Complexity: O(M+N) where M and N are the sizes of A and B respectively.
Expected Auxiliary Space: O(M+N)  


Constraints:
1<= M,N <= 104
String may contain duplicate characters.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            
            vector<int> h1(26,0);
             vector<int> h2(26,0);
            for(int i = 0  ; i<A.size();i++){
                h1[A[i]-'a']++;
            }
             for(int i = 0  ; i<B.size();i++){
                h2[B[i]-'a']++;
            }
        string str ="";
        for(int i=0;i<26;i++){
           if((h1[i]==0 && h2[i]>=1) || (h2[i]==0 && h1[i]>=1)){
               str+='a'+i;
           }
        }
        return (str.size()==0)?"-1":str;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends