/*
Ram is very fond of patterns. Once, his teacher gave him a pattern to solve. 
He gave Ram an integer n and asked him to build a pattern.
Help Ram build a pattern.
Example 1:
Input: 5
Output:
E
E D
E D C
E D C B
E D C B A
Example 2:
Input: 3
Output:
C
C B
C B A
Your Task:
You don't need to input anything. Complete the function 
printTriangle() which takes an integer n  as the input parameter and print the pattern.
Constraints:
1<= N <= 20
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for(int i = 1 ;i<=n;i++){
                        char ch = 65 +n-1;
            for(int j =1;j<=i;j++){
                cout<<ch<<" ";
                            ch--;

            }
            cout<<endl;
        }
    }
};
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends