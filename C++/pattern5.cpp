#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: "; 
    cin>>n;
    
    //Number vise pattern in decreasing order
    for(int i=n; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    //0-1 Number pattern in increasing order
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(i%2==0){
                if(j%2==0)
                    cout<<"1 ";
                else 
                    cout<<"0 ";
            }
            else{
                if(j%2==0)
                    cout<<"0 ";
                else 
                    cout<<"1 ";
            }
        }
        cout<<endl;
    }
    return 0;
}
