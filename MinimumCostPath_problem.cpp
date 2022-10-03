// An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
// From a cell (i, j), you can move in three directions:
// 1. ((i + 1),  j) which is, "down"
// 2. (i, (j + 1)) which is, "to the right"
// 3. ((i+1), (j+1)) which is, "to the diagonal"
// The cost of a path is defined as the sum of each cell's values through which the route passes.
//  Input format :
// The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

// The second line onwards, the next 'M' lines or rows represent the ith row values.

// Each of the ith row constitutes 'N' column values separated by a single space.
// Output format :
// Print the minimum cost to reach the destination.
// Constraints :
// 1 <= M <= 10 ^ 2
// 1 <= N <=  10 ^ 2

// Time Limit: 1 sec
// Sample Input 1 :
// 3 4
// 3 4 1 2
// 2 1 8 9
// 4 7 8 1
// Sample Output 1 :
// 13

#include <bits/stdc++.h>
using namespace std;

#include "solution.h"

int helper(int **input, int m, int n, int row, int col){
    if(row==m-1 && col==n-1){
        return input[row][col];
    }
    int side=INT_MAX, down=INT_MAX, diagonal=INT_MAX;
    
    if(row<m-1){
         down = helper(input, m, n, row+1, col);
    }
    if(col<n-1){
         side = helper(input, m, n, row, col+1);
    }
    if(row<m-1 && col<n-1){
         diagonal = helper(input, m, n, row+1, col+1);
    }
    return input[row][col] + min(side, min(row, col));
}


int minCostPath(int **input, int m, int n)
{
    return helper(input, m, n, 0, 0);
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}
