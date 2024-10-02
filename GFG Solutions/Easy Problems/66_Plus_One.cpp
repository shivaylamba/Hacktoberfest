#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> plusone(vector<int>& digits){
        int i = digits.size() -1;
        while(i>=0){
            if(digits[i]!=9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
            i--;
        }
        vector<int> carry(digits.size()+1);
        carry[0]=1;
        return carry;
    }
};
int main(){
  Solution s;
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i< n;i++){
        cin>>arr[i];
    }
    vector<int> result = s.plusone(arr);
    for(int i:result){
        cout<<i<<"\t";
    }
  }

}