#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid= (start+end)/2;
        if(arr[mid]==m){
            cout<<mid<<endl;
            return 0;
        }
        if(arr[mid]>m){
            end = mid-1;
        }else{
            start=mid+1;
        }

    }
    cout<<-1<<endl;
    return 0;
}
