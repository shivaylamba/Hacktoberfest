//to find unique number in a array of numbers
//hint : Use XOR
#include <iostream>
#include <bits/stdc++.h>
#include  <vector>
using namespace std;

int unique(int a[] , int n){

    int xorsum = 0;
    for(int i = 0; i < n; i++){
        xorsum ^= a[i];
    }
    return xorsum;

}
int main() 
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << unique(a,n);
    return 0;

}
