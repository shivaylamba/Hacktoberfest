/*
Sort a String
Given a string consisting of lowercase letters, arrange all its letters in ascending order. 

Example 1:

Input:
S = "edcab"
Output: "abcde"
Explanation: characters are in ascending
order in "abcde".
Example 2:

Input:
S = "xzy"
Output: "xyz"
Explanation: characters are in ascending
order in "xyz".


Your Task:  
You don't need to read input or print anything. Your task is to complete the function sort() which takes the string as inputs and returns the modified string.

Expected Time Complexity: O(|S| * log |S|)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |S| ≤ 105
S contains only lowercase alphabets.
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string sort(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << sort(s) << endl;
    }
return 0;
}




// } Driver Code Ends

// Using inbuild method
// Time Complexity O(n*log(n))
string sort(string s){
    //complete the function here
    sort(s.begin(),s.end());
    return s;
}