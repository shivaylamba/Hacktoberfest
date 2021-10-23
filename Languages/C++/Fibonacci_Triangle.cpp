#include<Bits.stdc++.h>
using namespace std;

int main(){
  int a,b,n,c;
  cout<<"Enter the limit : ";
  cin>>n;
  for(int i=0;i<n;i++){
    a=0;
    b=1;
    cout<<b<<"\t";
    for(int j=i;j<i;j++){
      c=a+b;
      cout<<c<<"\t";
      a=b;
      b=c;
    }
    cout<<"\n";
  }
  return 0;
}
