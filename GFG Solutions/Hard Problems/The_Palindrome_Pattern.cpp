/*
The Palindrome Pattern
Given a two-dimensional integer array arr of dimensions n x n, consisting solely of zeros and ones, identify the row or column (using 0-based indexing) where all elements form a palindrome. If multiple palindromes are identified, prioritize the palindromes found in rows over those in columns. Within rows or columns, the palindrome with the smaller index takes precedence. The result should be represented by the index followed by either 'R' or 'C', indicating whether the palindrome was located in a row or column. The output should be space-separated. If no palindrome is found, return the string -1.

Examples:

Input: 
arr[][] =  [[1, 0, 0], 
           [0, 1, 0],
           [1, 1, 0]]
Output: 1 R
Explanation: In the first test case, 0-1-0 is a palindrome 
occuring in a row having index 1.
Input: 
arr[][] =   [[1, 0],
           [1, 0]]
Output: 0 C
Explanation: 1-1 occurs before 0-0 in the 0th column. And there is no palindrome in the two rows.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

Constraints:
1<= arr.size <= 50
0 <= arr[i][j] <= 1
*/
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n1 = -1  , n = arr.size();
        string ans = "";
        // Check for the Row PalinDrome
        for(int i = 0  ;i<n;i++){
            bool flag = 1;
            int j1 = 0 , j2 = n-1;
            while(j1<j2){
                if(arr[i][j1]!=arr[i][j2]){ flag=0; break;}
                j1++ ; j2--;
            }
            if(flag){
                ans = to_string(i)+" R";
                return ans;
            }
        }
        // if(ans.size()!=0) return ans;
        
        // Check for the Column PalinDrome
        for(int j = 0  ;j<n;j++){
            bool flag = 1;
            int i1 = 0 , i2 = n-1;
            while(i1<i2){
                if(arr[i1][j]!=arr[i2][j]){ flag=0; break;}
                i1++ ; i2--;
            }
            if(flag){
                ans = to_string(j)+" C";
                return ans;
            }
        }
        // if(ans.size()!=0) return ans;
        return "-1";
    }
};