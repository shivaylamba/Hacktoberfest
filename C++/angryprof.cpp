// first-commit
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n,k;
    
    for(int i=0;i<t;i++){
        cin>>n>>k;
        int arr[n];
        int cnt=0;
        for(int j=0;j<n;j++){
            cin>>arr[j];
            if(arr[j]<=0){
                cnt++;
            }
        }
        
        if (cnt>=k)
        {
            cout<<"NO";
        }
        else{
            cout<<"YES";
        }
    }

    return 0;
}