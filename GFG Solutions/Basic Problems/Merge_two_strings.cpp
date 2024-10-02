/*
Given two strings S1 and S2 as input, the task is to merge them alternatively i.e. the first character of S1 then the first character of S2 and so on till the strings end.
NOTE: Add the whole string if other string is empty.
Example 1:
Input:
S1 = "Hello" S2 = "Bye"
Output: HBeylelo
Explanation: The characters of both the 
given strings are arranged alternatlively.
â€‹Example 2:
Input: 
S1 = "abc", S2 = "def"
Output: adbecf
Explanation: The characters of both the
given strings are arranged alternatlively.
Your Task:
You don't need to read input or print anything. Your task is to complete the function merge() which takes the strings S1 and S2 as input and returns the resultant string by merging both S1 and S2 alternatively starting from S1.
Expected Time Complexity: O(|S1| + |S2|).
Expected Auxiliary Space: O(1).
Constraints:
1<=|S1|, |S2| <=103
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string merge (string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends
string merge (string s1, string s2)
{
    // your code here
    string ans = "";
    int i = 0 , j = 0 ; 
    while(i<s1.size() && j<s2.size()){
        ans.push_back(s1[i++]);
        ans.push_back(s2[j++]);
    }
    while(i<s1.size()){
                ans.push_back(s1[i++]);
    }
    while(j<s2.size()){
                ans.push_back(s2[j++]);
    }
    return ans;
}