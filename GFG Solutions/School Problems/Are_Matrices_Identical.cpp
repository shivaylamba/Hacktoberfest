/*
Given two square matrices Grid1 and Grid2 with the 
same dimensions(NxN).Check whether they are identical or not.
Your Task:
You don't need to read input or print anything.
Your task is to complete the function areMatricesIdentical() 
which takes the integer N and two 2D arrays Grid1 and Grid2 as
input parameters and returns 1 if the matrices are identical.Otherwise,it returns 0.

Expected Time Complexity:O(N2)
Expected Auxillary Space:O(1)
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int areMatricesIdentical(int N, vector<vector<int>> Grid1,
                             vector<vector<int>> Grid2) {
        // code here
        int flag =0;
            for(int i=0;i<N;i++){
          for(int j=0;j<N;j++){
          if(Grid1[i][j] == Grid2[i][j]){
              flag = 1;
          }
          else{
              flag =0;
              break;
          }
              
          }
             if(flag==0){
              break;
          }
    }
    return (flag==0)?0:1;
                    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> Grid1(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> Grid1[i][j];
        vector<vector<int>> Grid2(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> Grid2[i][j];
        Solution ob;
        cout << ob.areMatricesIdentical(N, Grid1, Grid2) << "\n";
    }
}
// } Driver Code Ends