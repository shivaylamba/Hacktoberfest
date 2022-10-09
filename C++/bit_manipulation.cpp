#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos){
    return (n >> pos) & 1;
}

int setBit(int n, int pos){
    return (n | (1 << pos));
}

int clearBit(int n,int pos){
    int mask = ~(1 << pos);
    return (n & mask);
}

int updateBit(int n,int pos, int value){
    int mask = ~(1 << pos);
    n = n & mask;
    return (n | (value << pos));
}

int computeXOR(int n){
    if(n%4 == 0) return n;
    else if(n%4 == 1) return 1;
    else if(n%4 == 2) return n+1;
    else return 0;
}

int numberofOnes(int n){
    int count =0;
    while(n){
        n = n & (n-1);
        count++;
    }
    return count;
}

bool ispowerof2(int n){
    return (n && !(n & n-1));
}

void subsets(int arr[], int n){
    for(int i=0; i<(1 << n); i++){
        for (int j = 0; j < n; j++){
            if(i & (1 << j)) 
                cout << arr[j] << " ";
        }
        cout << endl;
    }
}

int unique(int arr[], int n){
    int xorsum = 0;
    for(int i=0; i<n; i++)
        xorsum ^= arr[i];
    return xorsum;
}

int32_t main(){
    int n,pos,value;
    cin >> n;
    // cin >> pos;
    // cin >> value;
    // int arr[n];
    // for(int i=0; i< n; i++)
        // cin >> arr[i];
    // cout << getbit(n,pos) << endl;
    // cout << setbit(n,pos) << endl;
    // cout << clearbit(n,pos) << endl;
    // cout << updatebit(n,pos,value) << endl;
    // cout << computeXOR(n) << endl;
    // cout << numberofOnes(n) << endl;
    // cout << ispowerof2(n) << endl;
    // cout << subsets(arr,n) << endl;
    // cout << unique(arr,n) << endl;
}
