/*
Given a string S, write a program to count the occurrence of Lowercase characters, Uppercase characters, Special characters and Numeric values in the string.
Note: There are no white spaces in the string.

Example 1:

Input:
S = "#GeeKs01fOr@gEEks07"
Output:
5
8
4
2
Explanation: There are 5 uppercase characters,
8 lowercase characters, 4 numeric characters
and 2 special characters.

Example 2:

Input: 
S = "*GeEkS4GeEkS*"
Output:
6
4
1
2
Explanation: There are 6 uppercase characters,
4 lowercase characters, 1 numeric characters
and 2 special characters.

Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which takes the string S as input and returns an array of size 4 where arr[0] = number of uppercase characters, arr[1] = number of lowercase characters, arr[2] = number of numeric characters and arr[3] = number of special characters.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).


Constraints:
1<=|S|<=105
*/
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> count (string s)
        {
            //code here.
            vector<int> arr(4,0);
            for(int i = 0 ; i<s.size();i++){
                if(isupper(s[i])){
                    arr[0]++;
                }
                else if(islower(s[i])){
                    arr[1]++;
                }
                else if(isdigit(s[i])){
                    arr[2]++;
                }
                else{
                    arr[3]++;
                }
            }
            return arr;
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
        vector <int> res = ob.count (s);
        for (int i : res)
            cout << i << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends