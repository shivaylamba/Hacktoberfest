#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    for(int i=n-1;i>=1;i--){
        n=n*i;
    }
    return n;
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The factorial of the given number is: "<<factorial(n);
    return 0;
}
