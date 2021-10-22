#include<iostream>
#include<cmath>
using namespace std;

int main(){
int n;
cin>>n;
 int c=0;
//bool flag=0;

for(int i=1;i<=n;i++){
    if(n%i==0){
        c++;
    }
}
    if (c==2)
        cout<<"Prime Nos"<<endl;
    else
        cout<<"Not a Prime no"<<endl;

    return 0;
}
