/*
Given a matrix of size N x N. Print the elements of the matrix in the snake like 
pattern depicted below.
Example 1:
Input:
N = 3 
matrix[][] = {{45, 48, 54},
             {21, 89, 87}
             {70, 78, 15}}
Output: 
45 48 54 87 89 21 70 78 15 
Explanation:
Matrix is as below:
45 48 54
21 89 87
70 78 15
Printing it in snake pattern will lead to 
the output as 45 48 54 87 89 21 70 78 15.
Example 2:

Input:
N = 2
matrix[][] = {{1, 2},
              {3, 4}}
Output: 
1 2 4 3
Explanation:
Matrix is as below:
1 2 
3 4
Printing it in snake pattern will 
give output as 1 2 4 3.
Your Task:
You dont need to read input or print anything. Complete the function 
snakePattern() that takes matrix as input parameter and returns a list of 
integers in order of the values visited in the snake pattern. 
Expected Time Complexity: O(N * N)
Expected Auxiliary Space: O(N * N) for the resultant list only.
Constraints:
1 <= N <= 103
1 <= mat[i][j] <= 109
*/
//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
// } Driver Code Ends
class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        // code here
        vector<int> ans;
        int row_st = 0 , col_st = 0 ;
        int row_en = matrix.size() , col_en = matrix[0].size(); 
        while(row_st<row_en){
            if(row_st%2==0){
                for(int i = col_st ;i<col_en;i++){
                ans.push_back(matrix[row_st][i]);
            }
            }
            else{
                for(int i = col_en-1 ;i>=col_st;i--){
                ans.push_back(matrix[row_st][i]);
            }
            }
            row_st++;
        }
        return ans;
    }
};
//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int> result = ob.snakePattern(matrix);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends