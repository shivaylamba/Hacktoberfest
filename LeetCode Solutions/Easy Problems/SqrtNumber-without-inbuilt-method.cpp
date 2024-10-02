#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int sqrtNumber(int x){
    int counter=0;
     int i=1;
          while(x!=0 && x>0){
              x =x -i;
              if(x<0){
                return counter;
              }
              i+=2;
              counter++;
          }
        return counter;
    }
};
int main(){
    int n;
    cin>>n;
    Solution s;
    cout<<s.sqrtNumber(n)<<endl;
    return 0;
}