/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> matrix( n , vector<int> (n, 0)); 
      int total = n*n;
      int count =1;
      int rs = 0 , re = n-1 , cs= 0 , ce=n-1;
    while(rs<=re && cs<=ce && count<=total){
        for(int i=cs;count<=total && i<=ce;i++){
        matrix[rs][i] = count;
            count++;
        }
        rs++;
        for(int i=rs;count<=total && i<=re;i++){
            matrix[i][ce]=count;
            count++;
        }
        ce--;
        for(int i=ce;count<=total && i>=cs;i--){
            matrix[re][i]=count;
            count++;
        }
        re--;
        for(int i=re;count<=total && i>=rs;i--){
            matrix[i][cs]=count;
            count++;
        }
        cs++;
    }
return matrix;
    }
};