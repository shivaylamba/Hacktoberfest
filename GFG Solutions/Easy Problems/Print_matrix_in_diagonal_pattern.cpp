/*
Print matrix in diagonal pattern
Given a square matrix mat[][] of n*n size, the task is to determine the diagonal 
pattern which is a linear arrangement of the elements of the matrix as depicted in 
the following example:
Example 1:
Input:
n = 3
mat[][] = {{1, 2, 3},
           {4, 5, 6},
           {7, 8, 9}}
Output: {1, 2, 4, 7, 5, 3, 6, 8, 9}
Explaination:
Starting from (0, 0): 1,
Move to the right to (0, 1): 2,
Move diagonally down to (1, 0): 4,
Move diagonally down to (2, 0): 7,
Move diagonally up to (1, 1): 5,
Move diagonally up to (0, 2): 3,
Move to the right to (1, 2): 6,
Move diagonally up to (2, 1): 8,
Move diagonally up to (2, 2): 9
There for the output is {1, 2, 4, 7, 5, 3, 6, 8, 9}.
Example 2:
Input:
n = 2
mat[][] = {{1, 2},
           {3, 4}}
Output: {1, 2, 3, 4}
Explaination:
Starting from (0, 0): 1,
Move to the right to (0, 1): 2,
Move diagonally down to (1, 0): 3,
Move to the right to (1, 1): 4
There for the output is {1, 2, 3, 4}.
Your Task:
You only need to implement the given function matrixDiagonally() which takes a matrix mat[][] of size n*n as an input and returns a list of integers containing the matrix diagonally. Do not read input, instead use the arguments given in the function.
Expected Time Complexity: O(n*n).
Expected Auxiliary Space: O(1).
Constraints:
1 <= n <= 100
-100 <= elements of matrix <= 100
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
// Initialize indexes of element to be printed next 
    int i = 0, j = 0 , n =mat.size(); 
    vector<int> ans;
    // Direction is initially from down to up 
    bool isUp = true; 
  
    // Traverse the matrix till all elements get traversed 
    for (int k = 0; k < n * n;) { 
        // If isUp = true then traverse from downward 
        // to upward 
        if (isUp) { 
            for (; i >= 0 && j < n; j++, i--) { 
                ans.push_back(mat[i][j]); 
                k++; 
            } 
  
            // Set i and j according to direction 
            if (i < 0 && j <= n - 1) 
                i = 0; 
            if (j == n) 
                i = i + 2, j--; 
        } 
  
        // If isUp = 0 then traverse up to down 
        else { 
            for (; j >= 0 && i < n; i++, j--) { 
                ans.push_back(mat[i][j]); 
                k++; 
            } 
  
            // Set i and j according to direction 
            if (j < 0 && i <= n - 1) 
                j = 0; 
            if (i == n) 
                j = j + 2, i--; 
        } 
  
        // Revert the isUp to change the direction 
        isUp = !isUp; 
    } 
    return ans;
    }
};
//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends