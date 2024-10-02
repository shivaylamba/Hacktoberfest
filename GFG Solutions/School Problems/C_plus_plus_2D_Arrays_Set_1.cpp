/*
Given a 2-d array of integers having N*N elements, print the transpose of the array.

Example 1:

Input : arr[] = {{1,2,3}, {4,5,6}, 
                  {7,8,9}} and N = 3
Output : 1 4 7 2 5 8 3 6 9
Explanation:1 2 3       1 4 7
            4 5 6 ----> 2 5 8
            7 8 9       3 6 9
Transpose of array.

Example 2:

Input : arr[ ] = {{1, 2}, {1, 2}} 
                    and N = 2 
Output :  1 1 2 2
 

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function transpose() that takes a two-dimension array (arr), sizeOfArray (n), and return the transpose of the array. The driver code takes care of the printing.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(1).

 

Constraints:
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 1000
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define M 101

vector<vector<int>> transpose(int a[][M], int n);

int main()
{
    int t;
    cin>>t;
    int a[M][M];
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        vector<vector<int>> b;
        b = transpose(a, n);
        for(int i=0;i < n;i++)
        {
            for(int j=0;j<n;j++){
                cout << b[i][j] << " ";
            }
        }
        cout<<endl;
    }
}



// } Driver Code Ends


vector<vector<int>> transpose(int a[][M], int n)
{
    // Code here
    vector<vector<int>> vec( n , vector<int> (M, 0));
    for(int i = 0; i < n; i++) 
    { 
        for(int j = 0; j < M; j++) 
        { 
        vec[i][j] = a[j][i]; 
        } 
    }
    return vec;
}
