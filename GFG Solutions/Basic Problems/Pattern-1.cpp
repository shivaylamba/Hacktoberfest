/*
Given a number N, identify the pattern from  the given Examples and print the Output.
Example 1:
Input:
N = 4
Output:
ABCD
E$$F
G$$H
IJKL
Example 2:

Input:
N = 6
Output:
ABCDEF
G$$$$H
I$$$$J
K$$$$L
M$$$$N
OPQRST
 
Your Task:
You don't need to read input or print anything. Your task is to complete the function findThePattern() which takes an Integer N as input and returns a vector of strings where each line represents lines of the pattern.
For example, if N = 4, the vector v = {"ABCD", "E$$F", "G$$H", "IJKL"}.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
Constraints:
1 <= N <= 6
*/
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    vector<string> findThePattern(int n) {
        // code here
        char ch ='A';
        vector<string> ans;
        for(int i =1;i<=n;i++){
            string s ="";
            for(int j = 1;j<=n;j++){
                if(i==1 || i==n || j==1|| j==n){
                    s.push_back(ch++);
                }
                else{
                    s.push_back('$');
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        vector<string> v = ob.findThePattern(N);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<endl;
    }
    return 0;
}
// } Driver Code Ends