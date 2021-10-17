#include<iostream>
#include<climits>
 
using namespace std;

int secondLargest(int a[],int n){
    int l=INT_MIN;
    int s=INT_MIN;

    l=a[0];
    for(int i=1;i<n;++i){
        if(a[i]>l){
            s=l;
            l=a[i];
        }
    }
    return s;
}

void input(int a[],int n){
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
}

int main(){
    int a[100];
    int n;
    cin>>n;
    input(a,n);
    cout<<secondLargest(a,n)<<endl;
    return 0;
}