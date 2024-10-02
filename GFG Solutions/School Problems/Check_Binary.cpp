/*
Given a non-empty sequence of characters str, return true if sequence is Binary,
 else return falseYour 
Task:
Complete the function isBinary() which takes an string str as input 
parameter and returns 1 if str is binary and returns 0 otherwise.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(1)

Constraints:
1 <=T<= 50
1 <=Length of str<= 10000
*/
//{ Driver Code Starts
// C++ program to Print root to leaf path WITHOUT
// using recursion
#include <bits/stdc++.h>
using namespace std;
bool isBinary(string str);
// Driver program to test above functions
int main()
{
    string str;
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
       cin >> str;
       cout << isBinary(str) << endl;
    }
    return 0;
}
// } Driver Code Ends
// Return true if str is binary, else false
bool isBinary(string str)
{
    int i=0 ,flag =0;
   // Your code here
   while(i<str.length()){
       if(str[i]=='1' || str[i]=='0'){
           flag =1 ;
       }
       else{
           flag =0;
           break;
       }
       i++;
   }
   return (flag==0)?0:1;
}