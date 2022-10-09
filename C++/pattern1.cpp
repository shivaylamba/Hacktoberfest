#include<iostream>
using namespace std;
int main(){
    int row,column;
    cin >> row >> column;
    
    //To print a completely filled rectangle of given rows and columns 
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            cout<<"*";
        }
        cout<<endl; 
    }

    cout<<endl;
    
    //To print a hollow rectangle of given rows and columns
    for(int i=1; i<=row; i++){
        for(int j=1; j<=column; j++){
            if(i==1 || i==row || j==1 || j==column) 
            cout<<"*";
            
            else
            cout<<" ";
        }
        cout<<endl; 
    }
    return 0;
}