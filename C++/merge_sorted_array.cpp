#include<iostream>
 
using namespace std;

void mergeSortedArray(int a[],int n,int b[],int m,int c[]){
    int i=0,j=0,k=0;
    for( ; i<n && j<m ;){
        // if(a[i]==b[j]){
        //     c[k]=a[i];
        //     i++;
        //     j++;
        //     k++;
        // } else 
        if (a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        } else{
            c[k]=b[j];
            j++;
            k++;
        }

    }
    if(i<n){
        for(;i<n;++i,++k)
            c[k]=a[i];
    }else if(j<m){
        for(;j<m;++j,++k)
            c[k]=b[j];
    }
}

void input(int a[],int n){
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
}

void output(int a[],int n){
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
}

int main(){
    int a[100],b[100],c[100];
    int n,m;
    cin>>n;
    input(a,n);
    cin>>m;
    input(b,m);
    mergeSortedArray(a,n,b,m,c);
    output(a,n);
    cout<<endl;
    output(b,m);
    cout<<endl;
    output(c,n+m);

    
    return 0;
}