//complete longest arithmetic array problem
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int last_diff =arr[1]-arr[0];
    int curr_diff;
    int max_count=2;    //the length of arr[1]-arr[0]
    int curr_count=2;
    int i=2;
    while(i<n){
        curr_diff=arr[i]-arr[i-1];
        if(curr_diff==last_diff){
            curr_count++;
        }
        else{
            last_diff=curr_diff;
            max_count=max(curr_count,max_count);
            curr_count=2;
        }
        i++;
    }
    cout<<max_count;
    return 0;
}