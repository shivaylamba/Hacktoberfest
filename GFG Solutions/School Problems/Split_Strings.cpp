/*
Given a string S which consists of alphabets , numbers and special characters. 
You need to write a program to split the strings in three different strings S1, S2 and S3 
such that the string S1 will contain all the alphabets present in S , 
the string S2 will contain all the numbers present in S and S3 will contain 
all special characters present in S.  The strings S1, S2 and S3 should have 
characters in same order as they appear in input.
Example 1:
Input:
S = geeks01for02geeks03!!!
Output:
geeksforgeeks
010203
!!!
Explanation: The output shows S1, S2 and S3. 
Example 2:
Input:
S = **Docoding123456789everyday##
Output:
Docodingeveryday
123456789
**##
Your Task:  
You dont need to read input or print anything. 
Complete the function splitString() which takes the string S as 
input parameters and returns a list of strings containing S1, S2 and S3 
respectively. If you return an empty string the driver will print -1.
Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(N)
Constraints:
1 ≤ |S| ≤ 105
*/
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 
// } Driver Code Ends
//User function Template for C++
class Solution
{   
public:
    vector<string> splitString(string S) 
    { 
        // code here 
        vector<string> ans;
        string number="",specialchar = "";
        int i = 0 ;
        while(i<S.size()){
            if(isalpha(S[i])){
                i++;
            }
            else if(isdigit(S[i])){
                number.push_back(S[i]);
                S.erase(i,1);
            }
            else{
                specialchar.push_back(S[i]);
                S.erase(i,1);
            }
        }
        ans.push_back(S);
        ans.push_back(number);
        ans.push_back(specialchar);
        return ans;
    } 
};
//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        vector<string> result = ob.splitString(S);
        for (int i = 0; i < result.size(); ++i)
        {
            if(result[i] == "")
                cout<<-1<<"\n";
            else
                cout<<result[i]<<"\n";
        }
    }
    return 0; 
} 
// } Driver Code Ends