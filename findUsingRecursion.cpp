#include<iostream>
#include<vector>
using namespace std;
void setter(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    }
void max(vector<int> & arr){
     int max=0;
    for(int i=0;i<arr.size();i++ ){
       
        if(arr[i]>max){
            max=arr[i];
        }
        
    }
    cout<<max;
}
void find(vector<int> & arr,int n){
     int flag;
    for(int i=0;i<arr.size();i++ ){
       
        if(arr[i]==n){
           flag=i;
        }
        
    }
    cout<<flag;
}
void min(vector<int> & arr){
     int min=0;
    for(int i=0;i<arr.size();i++ ){
       
        if(arr[i]<min){
            min=arr[i];

        }
        
    }
    if(min==0){
        for(int i=0;i<arr.size();i++){
       if(arr[i]>min){
           min=arr[i];
           break;
       }
        }
    }
    cout<<min;
}
int main(){
    vector<int> arr(5,0);
    setter(arr);
    
    max(arr);
    min(arr);
    find(arr);
    return 0;
}
