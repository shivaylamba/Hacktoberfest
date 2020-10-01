#include<iostream>
#include<vector>
using namespace std;
void setter(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    }
void getter(vector<int> & arr){
    for(int i=0;i<arr.size();i++ ){
        cout<<arr[i];
    }
}

int main(){
    vector<int> arr(10,0);
    setter(arr);
    getter(arr);
    return 0;
}
