/*
Remove consonants from a string
Given a string S, remove all consonants and print the modified string that contains vowels only.

Example 1:

Input
S = "abEkipo"
Output
aEio
Explanation : a, E, i, o are only vowels in the string.
Example 2:

Input
S = "rrty"
Output
No Vowel
Explanation: There are no vowels.

Your Task: You don't need to read input or print anything.Your task is to complete the function removeConsonants() which takes a string as input parameters, and returns the modified string that contains vowels only. If there is no vowel present in the string S, then return "No Vowel".

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints
1 <= |S| <= 105
The string should consist of only alphabets.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    private:
    bool isVowel(char ch){
        return (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' ||
        ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    public:
    string removeConsonants(string s){
    //complete the function heredef removeConsonants(s):
    int i = 0;
    while(i<s.size()){
        if(!isVowel(s[i])){
            s.erase(i,1);
        }
        else{
            i++;
        }
    }
    return (s.size()==0)?"No Vowel":s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.removeConsonants(s) << "\n";
    }
return 0;
}
// } Driver Code Ends