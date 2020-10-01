#include<iostream>
using namespace std;
int main(){
    bool arr[100] = {0};
    for(int i=2;i<100;i++){
        if(arr[i]==0){
            for(int j=2;i*j<100;j++){
                arr[i*j] = 1;
            }
        }
    }
    for(int i=2;i<100;i++){
        if(arr[i]==0){
            cout<<i<<endl;
        }
    }
}
