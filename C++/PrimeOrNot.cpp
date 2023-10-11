#include<iostream>
#include<cmath>
using namespace std;

int main(){
int n;
cin>>n;        //input number
if(n==1)
    cout<<"Non Prime No."<<endl;
if(n==2||n==3)
     cout<<"Non Prime No."<<endl;
if(n%2==0||n%3==0)
    cout<<"Non Prime No."<<endl;
bool flag=0;

for(int i=2;i<=sqrt(n);i++){
    if(n%i==0){
        cout<<"Non Prime No.";
        flag=1;
        break;
    }                             // if the no have more factor other than 1 and itself
}
if(flag==0)
    cout<<"Prime No."<<endl;
    return 0;
}
