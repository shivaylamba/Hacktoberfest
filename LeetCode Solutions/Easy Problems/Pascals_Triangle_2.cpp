#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
   long long int coef = 1;
  // Write your code here.
      vector<int> ans ;
    for(int j=0;j<=rowIndex;j++){
  if( j==0 || rowIndex==0){
   coef =1;
  }
  else{
    coef = coef*(rowIndex-j+1)/j;
  }
   ans.push_back(coef);
    }
  return ans;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        vector <int> res = ob.getRow(n);
        for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
        cout<<endl;
    }
}
// } Driver Code Ends