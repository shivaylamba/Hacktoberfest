/*
Check if a string is Isogram or not
Given a string S of lowercase alphabets, check if it is isogram or not. An Isogram is a string in which no letter occurs more than once.

Example 1:

Input:
S = machine
Output: 1
Explanation: machine is an isogram
as no letter has appeared twice. Hence
we print 1.
Example 2:

Input:
S = geeks
Output: 0
Explanation: geeks is not an isogram
as 'e' appears twice. Hence we print 0.
Your Task:
This is a function problem. You only need to complete the function isIsogram() that takes a string as a parameter and returns either true or false.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
Note: N = |S|

Constraints:
1 <= |s| <= 103
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if a string is Isogram or not.
//     Approach -1
    bool isIsogram(string s)
    {
        //Your code here
        unordered_map<char,int> f;
        for(char &ch:s){
            f[ch]++;
        }
        for(auto i:f){
            if(i.second>1){
                return 0;
            }
        }
        return 1;
    }
//     Approach -2
 bool isIsogram1(string s)
    {
        //Your code here
    vector<int> freq(26,0);
    for(char &ch:s){
        freq[ch - 'a']++;
    }
    for(int x:freq){
        if(x>1){
            return 0;
        }
    }
    return 1;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.isIsogram(s)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends