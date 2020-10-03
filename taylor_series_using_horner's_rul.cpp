#include<bits/stdc++.h>
using namespace std;
int horners(int x,int n){
    static int s=1;
    if(n==0)
    return s;
    else{
        s=1+x/n*s;
        return (x,n-1);
    }
}
int main(){
    cout<<horners(2,10);
}