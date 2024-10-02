/*
Sort the string in descending order
Given a string str containing only lower case alphabets, the task is to sort it in 
lexicographically-descending order.
Example 1:
Input: str = "geeks"
Output: "skgee"
Explanation: It's the lexicographically-
descending order.
â€‹Example 2:
Input: str = "for"
Output: "rof"
Explanation: "rof" is in
lexicographically-descending order.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function 
ReverseSort() which takes the string str as inputs and returns the modified string.
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ |str| ≤ 105
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string ReverseSort(string str);
int main(){
    int t;
    cin >> t;
    while(t--){

        string s;
        cin >> s;
        cout << ReverseSort(s) << endl;
    }
return 0;
}
// } Driver Code Ends
// Time Complexity: O(Max_CHAR*n) which becomes O(n) as MAX_CHAR is  constant,So Overall Time Complexity:- O(n) where n is the length of the string.  
// Auxiliary Space: O( 1 ).
string ReverseSort(string str){
    //complete the function here
        vector<int> freq(26,0);
    for(char &ch:str){
        freq[ch-'a']++;
    }
    str="";
    for(int i=25;i>=0;i--){
        for(int j=0;j<freq[i];j++){
            str+=('a'+i);
        }
    }
    return str;
}