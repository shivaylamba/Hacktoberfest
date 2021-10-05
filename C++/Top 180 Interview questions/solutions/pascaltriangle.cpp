class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      // first we generate the vector with the given number
      // of ros
        vector<vector<int>> r(numRows);
        for(int i = 0 ; i < numRows ; i++)
        {
            r[i].resize(i+1);
            r[i][0]=r[i][i] = 1;
            // changing the first and the last element
            // iterating in the all the middle elements
            for(int j = 1 ; j < i ; j++)
            {
               r[i][j] = r[i-1][j-1] + r[i-1][j]; 
            }
        }
        return r;
    }
};