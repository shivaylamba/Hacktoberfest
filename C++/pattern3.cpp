#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number: "; 
    cin>>n;

    /*//Print stars in decreasing order
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }*/

    //Print stars in increasing order
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    //Print numbers in increasing order
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    //Print Floyd's triangle
    int a=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<a<<" ";
            a++;
        }
        cout<<endl;
    }

    return 0;
}
