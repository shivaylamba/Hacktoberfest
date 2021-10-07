#include<iostream>
#include<cmath>
using namespace std;

int main(){
int n;
cin>>n;
bool flag=0;

for(int i=2;i<=sqrt(n);i++){
    if(n%i==0){
        cout<<"Not a Prime No.";
        flag=1;
        break;
    }
}
if(flag==0){
    cout<<"its a Prime No."<<endl;
}

    return 0;
}
