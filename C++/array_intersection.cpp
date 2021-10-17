#include<iostream>
#include<algorithm>
 
using namespace std;

void arrayIntersection(int input1[],int n,int input2[],int m){
    int i=0;
    int j=0;
    while(i!=n && j!=m){
        if(input1[i]==input2[j]){
            cout<<input1[i]<<" ";
            i++;
            j++;
        }
        else if(input1[i]<input2[j]){
            i++;
        }
        else{
            j++;
        }
    }
}

void getArray(int a[],int n){
    for(int i=0;i<n;++i)
        cin>>a[i];
}

int main(){
    int n,m;
    int input1[100],input2[100];

    //input array
    cin>>n;
    getArray(input1,n);
    cin>>m;
    getArray(input2,m);

    //Approach 1  

    sort(input1,input1+n);
    sort(input2,input2+m);

    arrayIntersection(input1,n,input2,m);
    cout<<endl;

    //Approach 2 Hashmap
    int arr[100]={0};
    for(int i=0;i<n;++i){
        arr[input1[i]]++;
    }
    for(int i=0;i<m;++i){
        arr[input2[i]]--;
    }
    for(int i=0;i<n;++i){
        if(arr[input1[i]]==0)
            cout<<input1[i]<<" ";
    }
    return 0;
}