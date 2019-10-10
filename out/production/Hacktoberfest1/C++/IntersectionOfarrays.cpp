#include<iostream>
#include<map>
using namespace std;
void Inter(int arr1[],int arr2[],int n){
    int arr[1000];
    map<int,int> mymap;
    for(int i=0;i<n;i++){
        mymap[arr1[i]]++;
    }
    int k=0;
    for(int i=0;i<n;i++){
        if(mymap.find(arr2[i])!=mymap.end() && mymap[arr2[i]]!=0){
            arr[k++]=arr2[i];
            mymap[arr2[i]]--;
        }
    }
    for(int i=0;i<k;i++){
        for(int j=i;j<k-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"[";
    for(int i=0;i<k-1;i++){
        cout<<arr[i]<<", ";
    }
    cout<<arr[k-1]<<"]";
    return;
}
int main(){
    int n;
    cin>>n;
    int arr1[1000];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int arr2[1000];
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    Inter(arr1,arr2,n);
    return 0;
}
