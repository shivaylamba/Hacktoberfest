#include<bits/stdc++.h>
using namespace std;
int fact(int n){
    int factorial=1;
    for (int i = 2; i <=n; i++)
    {
        factorial*=i;
    }
    return factorial;
    
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int comb = fact(i)/(fact(j)*fact(i-j));
            cout<<comb<<" ";
    }
    cout<<endl;
    }
    return 0;
}
