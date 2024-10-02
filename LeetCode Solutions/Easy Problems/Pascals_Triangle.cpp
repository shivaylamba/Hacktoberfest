#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
            int coef = 1;
  // Write your code here.
   vector<vector<int>> ans ;
  for(int i=0;i<numRows;i++){
  vector<int> ans2;
    for(int j=0;j<=i;j++){
  if( j==0 || i==0){
   coef =1;
  }
  else{
    coef = coef*(i-j+1)/j;
  }
   ans2.push_back(coef);
    }
    ans.push_back(ans2);
  }
  return ans;
    }
};
// Another Optimized Method
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows, vector<int>());
        for(int i=0;i<numRows;i++)
        {
            v[i].resize(i + 1);
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                    v[i][j]=1;
                else
                {
                    v[i][j]=v[i-1][j-1]+v[i-1][j];
                }
            }
        }
        return v;
    }
};
