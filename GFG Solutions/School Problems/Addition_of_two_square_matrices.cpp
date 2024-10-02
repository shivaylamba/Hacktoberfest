/*
Given two square matrices matrixA and matrixB of size n x n.  Find the addition of these two matrices.

Note :- You don't have to return anything in this question (Refer YourTask section).
 

Example 1:

Input: matrixA = {{1, 2}, {3, 4}},
matrixB = {{4, 3}, {2, 1}}
Output: {{5, 5}, {5, 5}}
Example 1:

Input: matrixA = {{2, 2}, {2, 2}},
matrixB = {{3, 3}, {3, 3}}
Output: {{5, 5},{5, 5}}
 

Your Task:
You don't need to read or print anything. Your task is to complete the function Addition() which takes matrixA and matrixB as input parameters and adds two matrices. Do the addition without using extra memory. The output matrix must be in matrixA.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(1)
 

Constraints:
1 <= n <= 100
*/
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void Addition(vector<vector<int> >& matrixA, vector<vector<int>>&matrixB) {
        // Code here
        for(int i = 0; i<matrixA.size();i++){
            for(int j = 0 ; j<matrixA[i].size();j++){
                matrixA[i][j]+=matrixB[i][j];
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrixA(n, vector<int>(n,0));
		vector<vector<int>> matrixB(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrixA[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrixB[i][j];
			}
		}
		Solution ob;
		ob.Addition(matrixA, matrixB);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout << matrixA[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends