/*
Given the marks of N students in an Array A, calculate the mean.
Note: If result is a Decimal Value, find it's floor Value.
Your Task:
You don't need to read input or print anything. Your task is to complete the function mean() which takes 1 Integer N and an Array A as input and returns the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 104
1 <= A[i] <= 104
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution {
  public:
    int mean(int N , int A[]) {
        // code here
        for(int i=1 ;i<N;i++){
            A[0]+=A[i];
        }
        return A[0]/N;
         
    }
};
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.mean(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends