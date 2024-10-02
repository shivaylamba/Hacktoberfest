/*
Geek is very fond of patterns. Once, his teacher gave him a star pattern to solve. 
He gave Geek an integer n and asked him to build a pattern.
Help Geek to build a star pattern.
Example 1:
input:5
output:
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *
Your Task:
You don't need to input anything. Complete the function printDiamond() 
which takes  an integer n  as the input parameter and print the pattern.
Constraints:
1<= N <= 20
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        // code here
        for(int i = 1 ; i<=n;i++){
            for(int j=n-1;j>=i;j--){
                cout<<" ";
            }
            for(int j = 1;j<=i;j++){
                cout<<"*"<<" ";
            }
            cout<<endl;
        }
                for(int i = n ; i>=1;i--){
            for(int j=n-1;j>=i;j--){
                cout<<" ";
            }
            for(int j = 1;j<=i;j++){
                cout<<"*"<<" ";
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends