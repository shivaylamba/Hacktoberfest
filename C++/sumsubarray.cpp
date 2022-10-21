#include<iostream>
using namespace std;

int printallpairsn3(int arr[],int n){
    //brute force method
    int largest=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
        largest=max(sum,largest);
        }
        
    }
    return largest;
}

int printallpairsn2(int arr[],int n){
    //prefix sum method
    int a[n]={0};
    a[0]=arr[0];
    for(int i=1;i<n;i++){
        a[i]=a[i-1]+arr[i];
    }
    int largest=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum=a[j]-a[i-1];
        }
        largest=max(largest,sum);
    }
    return largest;
}

int printallpairsn1(int arr[],int n){
    //Kadane's algo method
    int sum=0,largest=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        largest=max(largest,sum);
        if(sum<arr[i]) sum=arr[i];
    }
    return largest;
}

int main(){
    int arr[]={-2,3,4,-1,5,-12,6,2,3};
    int n=sizeof(arr)/sizeof(int);
    cout<<printallpairsn3(arr,n)<<endl;
    cout<<printallpairsn2(arr,n)<<endl;
    cout<<printallpairsn1(arr,n);
}