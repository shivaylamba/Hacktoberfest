#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(n>2){
        return fib(n-1)+fib(n-2);
    }
    return 0;
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Fibonacci series till the given term is"<<endl;
    for(int i=1;i<=n;i++){
        cout<<fib(i)<<" ";
    }
    return 0;
}
