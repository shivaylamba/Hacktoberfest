//first repeating element
#include<bits/stdc++.h>
using namespace std;

const int N=1e6+2;
int temp_arr[N];
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //we have to perform like count sort;
    for(int i=0;i<N;i++){
        temp_arr[i]=-1;
    }

    int min_index=INT_MAX;
    for(int i=0;i<n;i++){
        if(temp_arr[arr[i]]==-1){
            temp_arr[arr[i]]=i;
        }
        else{
            min_index=min(min_index,temp_arr[arr[i]]);
        }
    }
    cout<<min_index+1;
    return 0;
}