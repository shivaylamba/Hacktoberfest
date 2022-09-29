#include<iostream>
using namespace std;


bool isPossible(int arr[], int n, int k, long long int mid){

    long long int bordlength_Sum=0;
    int paintercount=1;

    for(int i=0;i<n;i++)
    {
        if(bordlength_Sum+arr[i]<=mid)
        {
            bordlength_Sum=bordlength_Sum+arr[i];
        }
        else
        {
            paintercount++;
            if(paintercount>k || arr[i]>mid)
            {
                return false;
            }
            paintercount=arr[i];
        }
    }
    return true;
}

long long int minTime(int arr[], int n, int k){
    int s=0;
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    long long int e=sum;
    long long int ans=-1;
    long long int mid=s+(e-s)/2;

    while(s<=e){
        if(isPossible(arr, n, k, mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    int arr[]= {10, 20, 30, 40};
    int k=2;
    int n=4;
    cout<< minTime(arr, n, k) << endl;
    return 0;
}