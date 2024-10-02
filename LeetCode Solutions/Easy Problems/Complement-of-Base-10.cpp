#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) {
          int m=n;
           int mask=0;
     if(n==0){     // egde case (required)
       return 1;
     }
           while(m!=0){
            mask = (mask << 1)|1;
            m = m >> 1 ;
          }
          return ((~n)&mask);
    }
/*
    int findComplement(int num){
      vector<int> v;
      while(num!=0){
        v.push_back(num%2);
        num/=2;
      }
      for(int i=0;i< v.size();i++){
        if(v[i]==0){
          v[i]=1;
        }
        else{
          v[i]=0;
        }
      }
      for(int i=0;i< v.size();i++){
        num = num + v[i]*pow(2,i);
      }
      return num;
  }
*/
};
int main(){
    Solution s;
    int n;
    cin>>n;
    cout<<s.bitwiseComplement(n)<<endl;
    return 0;
}