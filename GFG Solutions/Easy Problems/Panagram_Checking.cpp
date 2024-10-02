/*
Given a string check if it is Panagram or not. A panagram is a sentence containing every letter in the English Alphabet (either lowercase or uppercase or both). For example, we say the letter A is present in the string if either 'a' is present or 'A' is present.

Example 1:

Input:
S = Bawds jog, flick quartz, vex nymph
Output: 1
Explanation: In the given input, there
are all the letters of the English
alphabet. Hence, the output is 1.
Example 2:

Input:
S = sdfs
Output: 0
Explanation: In the given input, there
aren't all the letters present in the
English alphabet. Hence, the output
is 0.
Your Task:
 You need to complete the function checkPangram() that takes a string as a parameter and returns true if the string is a panagram, or else it returns false.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).

Constraints:
1 ≤ |S| ≤ 104
*/
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
//Time Complexity: O(N), where N is the length of the string.
// Auxiliary Space: O(1)
     bool checkPangram (string s) {
        // your code here
    transform(s.begin(),s.end() , s.begin() , ::tolower);
        unordered_map<char,int> freq;
        for(char &ch:s){
            if(isalpha(ch)){
                freq[ch]++;
            }
        }
        return freq.size()==26?1:0;
    }
// Time Complexity O(n)
// Space Complexity O(1)
    bool checkPangram1 (string s) {
        // your code here
    transform(s.begin(),s.end() , s.begin() , ::tolower);
        vector<int> f(26,0);
        for(char &ch:s){
            if(isalpha(ch)){
                f[ch-'a']++;
            }
        }
        for(int i=0;i<f.size();i++){
            if(f[i]==0){
                return 0;
            }
        }
        return 1;
    }
// Time Complexity O(n)
// Space Complexity O(1)
    bool checkPangram2 (string s) {
        // your code here
    transform(s.begin(),s.end() , s.begin() , ::tolower);
        vector<int> f(26,0);
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ' && (s[i]>='a' && s[i]<='z')){
                f[s[i]-'a']++;
            }
        }
        for(int i=0;i<f.size();i++){
            if(f[i]==0){
                return 0;
            }
        }
        return 1;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends