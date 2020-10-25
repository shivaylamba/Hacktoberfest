/*
You are given an N*N sudoku grid (N is a multiple of 3).
Solve the sudoku and print the solution.
To learn more about sudoku, go to this link Sudoku-Wikipedia.
Input Format:
First line contains a single integer N.
Next N lines contains N integers each,
where jth integer int ith line denotes the value at ith row and jth column in sudoku grid.
This value is 0, if the cell is empty.
Constraints:
N=9 Solution exists for input matrix.
Output Format
Print N lines containing N integers each,
where jth integer int ith line denotes the value at ith row and jth column in sudoku grid,
such that all cells are filled.
Sample Input
9
5 3 0 0 7 0 0 0 0 
6 0 0 1 9 5 0 0 0 
0 9 8 0 0 0 0 6 0 
8 0 0 0 6 0 0 0 3 
4 0 0 8 0 3 0 0 1 
7 0 0 0 2 0 0 0 6 
0 6 0 0 0 0 2 8 0 
0 0 0 4 1 9 0 0 5 
0 0 0 0 8 0 0 7 9
Sample Output
5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9 
*/
#include<iostream>
#include<cmath>
using namespace std;
bool isValid(int sudoku[9][9], int n, int i, int j, int number){
	for(int x = 0; x < n; x++){
		if(sudoku[x][j] == number || sudoku[i][x] == number){
			return false;
		}
	}
	int nroot = sqrt(n);
	int startx = (i/nroot)*nroot;
	int starty = (j/nroot)*nroot;
	for(int x = startx; x < startx + nroot; x++){
		for(int y = starty; y < starty + nroot; y++){
			if(sudoku[x][y] == number){
				return false;
			}
		}
	}
	return true;
}
bool sudokuSolver(int sudoku[9][9], int n, int i = 0, int j = 0){
	//base case
	if(i == n){
		//print sudoku
		for(int x = 0; x < n; x++){
			for(int y = 0; y < n; y++){
				cout << sudoku[x][y] << " ";
			}
			cout << endl;
		}
		return true;
	}
	//row change
	if(j == n){
		return sudokuSolver(sudoku, n, i + 1, 0);
	}
	//non-empty
	if(sudoku[i][j] != 0){
		return sudokuSolver(sudoku, n, i, j + 1);
	}
	//solve
	for(int number = 1; number <= n; number++){
		if(isValid(sudoku, n, i, j, number)){
			sudoku[i][j] = number;
			bool isSolvable = sudokuSolver(sudoku, n, i, j + 1);
			if(isSolvable){
				return true;
			}
		}
	}
	sudoku[i][j] = 0;
	return false;
}
int main(){
	int n;
	cin >> n;
	int sudoku[9][9];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> sudoku[i][j];
		}
	}
	sudokuSolver(sudoku, n);
	return 0;
} 