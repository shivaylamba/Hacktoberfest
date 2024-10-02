/*
Given a matrix Grid[][] of size NxN. Calculate the absolute difference between the sums of its diagonals.

Example 1:

Input:
N=3
Grid=[[1,2,3],[4,5,6],[7,8,9]]
Output: 
0
Explanation:
Sum of primary diagonal = 1+5+9 = 15.
Sum of secondary diagonal = 3+5+7 = 15.
Difference = |15 - 15| = 0.
Example 2:

Input:
N=3
Grid=[[1,1,1],[1,1,1],[1,1,1]]
Output:
0
Explanation:
Sum of primary diagonal = 1+1+1=3.
Sum of secondary diagonal = 1+1+1=3.
Difference = |3-3| = 0.

Your Task:
You don't need to read input or print anything.Your task is to complete the function diagonalSumDifference() which takes an integer N and a 2D array Grid as input parameters and returns the absolutes difference between the sums of its diagonals.


Expected Time Complexity:O(N)
Expected Auxillary Space:O(1)


Constraints:
1<=N<=1000
-1000<=Grid[i][j]<=1000, for 0<=i,j
*/
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int diagonalSumDifference(int N, vector<vector<int>> Grid) {
        // code here
        int d1 = 0 , d2 = 0 ;
        for(int i=0;i<N;i++){
           d1+=Grid[i][i];
           d2+=Grid[N-i-1][i];
        }
        return abs(d1-d2);
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
        Solution ob;
        cout << ob.diagonalSumDifference(N, Grid1) << "\n";
    }
}
// } Driver Code Ends