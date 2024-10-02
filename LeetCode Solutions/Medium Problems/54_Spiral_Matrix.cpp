/*
Spiral Order Matrix Traversal

Problem: We have to print the given 2D matrix in the spiral order. Spiral
Order means that firstly, first row is printed, then last column is printed,
then last row is printed and then first column is printed, then we will come
inwards in the similar way.

Algorithm: (We are given 2D matrix of n X m ).
1. We will need 4 variables:
a. row_start(rs) - initialized with 0.
b. row_end(re) - initialized with n-1.
c. column_start(cs) - initialized with 0.
d. column_end(ce) - initialized with m-1.

2. First of all, we will traverse in the row row_start from column_start
to column_end and we will increase the row_start with 1 as we have
traversed the starting row.

3. Then we will traverse in the column column_end from row_start to
row_end and decrease the column_end by 1.

4. Then we will traverse in the row row_end from column_end to
column_start and decrease the row_end by 1.

5. Then we will traverse in the column column_start from row_end to
row_start and increase the column_start by 1.

6. We will do the above steps from 2 to 5 until row_start <= row_end
and column_start <= column_end.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/
#include <bits/stdc++.h> 
using namespace std;
vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 
{
    // Write your code here.
    vector<int> ans;
    int count = 0 ;
    int total = n*m;
    int rs = 0 ,re= n-1, cs = 0 ,ce = m-1;
    while(rs<=re && cs<=ce && count<total){
        for(int i=cs;count<total && i<=ce;i++){
            ans.push_back(matrix[rs][i]);
            count++;
        }
        rs++;
        for(int i=rs;count<total && i<=re;i++){
            ans.push_back(matrix[i][ce]);
            count++;
        }
        ce--;
        for(int i=ce;count<total && i>=cs;i--){
            ans.push_back(matrix[re][i]);
            count++;
        }
        re--;
        for(int i=re;count<total && i>=rs;i--){
            ans.push_back(matrix[i][cs]);
            count++;
        }
        cs++;
    }
return ans;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int m, n ;
    cin>>m>>n;
vector<vector<int>> vec( m , vector<int> (n)); 
for(int i = 0; i < m; i++) 
    { 
        for(int j = 0; j < n; j++) 
        { 
           cin>> vec[i][j];
        } 
    } 
for(int i = 0; i < m; i++) 
    { 
        for(int j = 0; j < n; j++) 
        { 
           cout<<vec[i][j]<<" ";
        }
        cout<<endl; 
    } 
    vector<int> res = spiralPathMatrix(vec,m,n);
    for(int x:res){
        cout<<x<<" ";
    }
return 0;
}