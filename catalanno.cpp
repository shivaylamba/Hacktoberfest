#include<bits/stdc++.h>// through binomial cofficient
using namespace std;
int catalanno(int no){
    int nob=1;
for(int i=no*2;i>no;i--){
nob*=i;
nob/=(no*2+1-i);
}
return nob/(no+1);
}
int main(){

int a,b;
cout<<"enter the total no's";
cin>>a;
int s;
for(int i=0;i<10;i++){
s=catalanno(i);
cout<<s<<endl;}
}
