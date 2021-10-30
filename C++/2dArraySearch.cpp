#include <iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"enter the range 2d array";
    cin>>n>>m;

    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0; i<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"matrix is :\n";
    for(int i=0;i<n;i++){
        for(int j=0;i<m;j++){
                cout<<arr[i][j]<<" ";
        }  
        cout<<"\n";
    }

    int search;
        cout<<"enter the search element";
        cin>>search;
    bool flag=false;
    
    for(int i=0;i<n;i++){
        for(int j=0; i<m;j++){
            if(arr[i][j]== search){
                cout<<arr[i][j]<<" ";
                flag=true;
            }
            cout<<"\n";
        }
    }
    if(flag){
        cout<<"element is found";
    }
    else{
        cout<<"element is not found";
    }
    return 0;
}
