/*
Given two strings S1 and S2 as input. Your task is to concatenate two strings and then reverse the string. Finally print the reversed string.

Example 1:

Input: S1 = "Geeks" , S2 = "forGeeks"
Output: "skeeGrofskeeG" 
Explanation: Concatenating S1 and S2 to 
get "GeeksforGeeks" then reversing it to 
"skeeGrofskeeG".
Example 2:

Input: S1 = "Practice" , S2 = "Geeks"
Output: "skeeGecitcarP"
Explanation: Concatenating S1 and S2 to
get "PracticeGeeks" then reversing it to
"skeegecitcarP".

Your Task:  
You dont need to read input or print anything. Complete the function conRevstr() which takes S1 and S2 as input parameter and returns the sting final_s after concatenating and reversing.

Expected Time Complexity: O(|S1| + |S2|)
Expected Auxiliary Space: O(|S1| + |S2|)

Constraints:
1<= |S1| <=1000
1<= |S2| <=1000
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string conRevstr(string s1, string s2) {
        // code here
      string ans = s1+s2;
      int i=0 , j = ans.size()-1;
      while(i<j){
          swap(ans[i++],ans[j--]);
      }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1, S2;
        cin >> S1;
        cin >> S2;
        Solution ob;
        cout << ob.conRevstr(S1, S2) << endl;
    }
    return 0;
}

// } Driver Code Ends