// Table Lookup
/*
You are given a 2D matrix, having n rows and m columns, such that the elements in each row as well elements in each column are sorted in non-decreasing order. Given an integer x
determine whether x is present in the matrix or not.
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


bool isPresent(vector<vector<int>> mat, int n, int m, int x){
     
     // Brute force: Liner Search - TC: O(N ^ 2) | ASC: O(1)
     /*
     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
                    if(mat[i][j] == x) return true;
          }
     }
     return false; 
     */

    // Using Binary Search - TC: O(N + M) | ASC: O(1)

    // smallest number is at postion [0][0],
    // largest number is at position [n-1][m-1]
    // if the value x is less than the smallest number and greater than the largest number then number does not exist in matrix.
    if(x < mat[0][0] || x > mat[n-1][m-1]) return false;
    int i = 0, j = m-1;
    while(i < n && j >= 0){
          if(mat[i][j] == x) return true;
          else if(mat[i][j] < x) i++;
          else j--;
    } 
    return false;  
}
int main() {
    eff;
    int n, m, x;
    cin>>n>>m>>x;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin>>mat[i][j];
      }
    }
    if(isPresent(mat, n, m, x)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  return 0;

}
