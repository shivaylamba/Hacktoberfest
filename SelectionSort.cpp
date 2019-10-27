#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    int temp=0;
    cin>>n;
    vector<int> arr(n,0);
    for(int m=0;m<n;m++){
        cin>>arr[m];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
             temp=arr[i];
             arr[i]=arr[j];
             arr[j]=temp;
            }
        }
    }
    for(int k=0;k<n;k++){
        cout<<arr[k]<<" ";
    }
}
