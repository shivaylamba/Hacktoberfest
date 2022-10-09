#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of Pyramid: ";
    cin >> n;
    
    //Printing Star Pyramid
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n-i; j++)
            cout<<" ";
        for (int j=1; j<=i; j++)
            cout<<"* ";
        cout << endl;
    }

    cout<<endl;

    //Printing Number pyramid
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n-i; j++)
            cout<<" ";
        for (int j=1; j<=i; j++)
            cout<<j<<" ";
        cout << endl;
    }

    //Printing Palindromic Pattern Image pyramid
    for (int i=1; i<=n; i++) {
        int j;
        for (j=1; j<=n-i; j++){
            cout<<" ";
        } 
        int k=i;
        for (; j<=n; j++){
            cout<<k--;
        }
        k=2;
        for (; j<=n+i-1; j++){
            cout<<k++; 
        }
        cout << endl;
    }

    //Star Pattern
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n-i; j++)
            cout<<" ";
        for (int j=1; j<=2*i-1; j++)
            cout<<"*";
        cout << endl;
    }
    for (int i=n; i>=1; i--) {
        for (int j=1; j<=n-i; j++)
            cout<<" ";
        for (int j=1; j<=2*i-1; j++)
            cout<<"*";
        cout << endl;
    }
    return 0;
}
