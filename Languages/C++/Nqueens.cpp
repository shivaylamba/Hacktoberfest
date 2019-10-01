#include<iostream>
using namespace std;
bool isafe( int arr[][11],int n,int x,int y){
    int arr1[2][8]={{-1,-1,0,1,1,1,0,-1},
                   {0,1,1,1,0,-1,-1,-1}};
    for(int k=0;k<8;k++){
        for(int i=x,j=y;i<n && i>=0 && j<n && j>=0;i+=arr1[0][k],j+=arr1[1][k]){
            if(arr[i][j]==1){
                return false;
            }
        }
    }
    return true;

}
int check(int arr[][11],int n,int y){
    if(y==n){
        /* cout<<"********************************"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"********************************"<<endl;*/
        return 1;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(isafe(arr,n,i,y)){
            arr[i][y]=1;
            sum+=check(arr,n,y+1);
            arr[i][y]=0;
        }
    }

    return sum;
}
int main(){
    int n;
    cin>>n;
    int arr[11][11]={};
    cout<<check(arr,n,0)<<endl;
    return 0;
}
