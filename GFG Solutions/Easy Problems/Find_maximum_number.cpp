/*
Given a number N, write a program to find a maximum number 
that can be formed using all of the digits of this number.
Note: The given number can be very large, so the input is taken as a String.
Example 1:
Input:
N = "38293367"
Output:
98763332 
Explanation:
98763332 is the largest number that
can be formed by rearranging the
digits of N.
Example 2:
Input:
N = "1203465"
Output:
6543210
Explanation:
6543210 is the largest number that
can be formed by rearranging the
digits of N.
Your Task:
You don't need to read input or print anything. Your task is to 
complete the function findMax() which takes a String N as input and returns the answer.
Expected Time Complexity: O(|N|)
Expected Auxiliary Space: O(constant)
Constraints:
1 <= |N| <= 105
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution {
  public:
   // time complexity is : O(n log n) 
  // Auxiliary Space: O(1) 
    string findMax(string s) {
        // code here
    sort(s.begin(), s.end(), greater<char>());
    return s;
    }
};
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string N;
        
        cin>>N;

        Solution ob;
        cout << ob.findMax(N) << endl;
    }
    return 0;
}
// } Driver Code Ends