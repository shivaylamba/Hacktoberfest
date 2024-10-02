/*
Count zeros in a sorted matrix
Given a N X N binary Square Matrix where each row and column of the matrix is sorted in ascending order. Find the total number of zeros present in the matrix.

Example 1:

Input:
N = 3
A = {{0, 0, 0},
     {0, 0, 1},
     {0, 1, 1}}
Output: 6
Explanation: 
The first, second and third row contains 3, 2 and 1
zeroes respectively.
Example 2:

Input:
N = 2
A = {{1, 1},
     {1, 1}}
Output: 0
Explanation:
There are no zeroes in any of the rows.
Your Task:
You don't need to read input or print anything. Your task is to complete the function countZeros() which takes a 2D matrix as input and returns the number occurring only once.

Expected Time Complexity: O(N ).
Expected Auxiliary Space: O(1).

Constraints
0 <   N  <= 103
0 <= A[i] <= 1
*/
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
public:
	int countZeros(vector<vector<int>>A)
	{
		//code here
		int j=0;
		int i=0 ,count=0;
		while(i<A.size()){
		    if(A[i][j]==0){
		        count++;
		    }
		    j++;
		    if(j==A[i].size()){
		        j=0;i++;
		    }
		}
		return count;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>A(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                cin>>A[i][j];
            }
        }
        Solution ob;
        cout<<ob.countZeros(A)<<'\n';
    }
    return 0;
}

// } Driver Code Ends