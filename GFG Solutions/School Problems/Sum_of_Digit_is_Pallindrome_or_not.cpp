/*
Given a number N.Find if the digit sum(or sum of digits) of N is a Palindrome number or not.
Note:A Palindrome number is a number which stays the same when reversed.Example- 121,131,7 etc.

Example 1:

Input:
N=56
Output:
1
Explanation:
The digit sum of 56 is 5+6=11.
Since, 11 is a palindrome number.Thus,
answer is 1.
Example 2:

Input:
N=98
Output:
0
Explanation:
The digit sum of 98 is 9+8=17.
Since 17 is not a palindrome,thus, answer
is 0.

Your Task:
You don't need to read input or print anything.Your Task is to complete the function isDigitSumPalindrome() which takes a number N as input parameter and returns 1 if the Digit sum of N is a palindrome.Otherwise it returns 0.


Expected Time Complexity:O(LogN)
Expected Auxillary Space:O(1)

Constraints:
1<=N<=109
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int checkPalin(int n){
            int ans=0;
          while(n>0){
            int ld = n%10;
            ans = ans*10 + ld;
            n/=10;
        }
        return ans;
  }
    int isDigitSumPalindrome(int N) {
        // code here
        int n1 =N;
        int ans  =0;
                while(n1>0){
            int ld = n1%10;
            ans+=ld;
            n1/=10;
        }
        int newN = checkPalin(ans);
        return (newN==ans)?1:0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}

// } Driver Code Ends