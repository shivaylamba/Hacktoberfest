#include<iostream>
 
using namespace std;


int minimumIndex(int a[],int n){
     int min=a[0],minIndex=0;
    for(int i=0;i<n;++i){
        if(a[i]<min){
                min=a[i];
                minIndex=i;
            }
    }
    return minIndex;
}

void selectionSort(int a[], int n){

    for(int i=0;i<n-1;++i){

        //Finding minimum element and storing its index
        // int min=a[i],minIndex=i;
        // for(int j=i;j<n;++j){
        //     if(a[j]<min){
        //         min=a[j];
        //         minIndex=j;
        //     }
        // }
        int minIndex=minimumIndex(a+i,n-i)+i;

        //Swapping
        int temp=a[i];                          // a[minIndex]==min
        a[i]=a[minIndex];
        a[minIndex]=temp;

    }

}

void input(int a[],int n){
    for(int i=0;i<n;++i)
        cin>>a[i];
}

void output(int a[],int n){
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
}

int main(){
    int a[100];
    int n;
    cin>>n;
    input(a,n);
    selectionSort(a,n);
    // for(int i=0;i<n-1;++i){
    //     cout<<minimumIndex(a+i,n)<<" ";
    // }
    
    output(a,n);
    
    return 0;
}