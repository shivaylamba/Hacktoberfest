/*
Stuck on a problem? Level up with 35% Off on premium GfG Courses and master coding! 
banner
Given a non null integer matrix Grid of dimensions NxM.Calculate the sum of its elements
Your Task:
You don't need to read input or print anything.Your task is to complete the function sumOfMatrix() which takes two integers N ,M and a 2D array Grid as input parameters and returns the sum of all the elements of the Grid.

Expected Time Complexity:O(N*M)
Expected Auxillary Space:O(1)

Constraints:
1<=N,M<=1000
-1000<=Grid[i][j]<=1000
*/
//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int sumOfMatrix(int N, int M, vector<vector<int>> Grid) {
        // code here
        int ans =0;
            for(int i=0;i<N;i++){
          for(int j=0;j<M;j++){
             ans += Grid[i][j];
          }               
         }
         return ans;
    }
};
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> Grid(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> Grid[i][j];
        Solution ob;
        cout << ob.sumOfMatrix(N, M, Grid) << "\n";
    }
}
// } Driver Code Ends