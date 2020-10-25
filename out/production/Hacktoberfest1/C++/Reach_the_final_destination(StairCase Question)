#include <iostream>
using namespace std;
int stepPerms(int n) {

    if(n<0){
        return 0;
    }
    else{
        return 1;
    }
    return stepPerms(n-1)+ stepPerms(n-2)+stepPerms(n-3);
}
int main(){
  int n;
  cin>>n;
  int ans=stepParams(n);
  cout<<ans;
}
