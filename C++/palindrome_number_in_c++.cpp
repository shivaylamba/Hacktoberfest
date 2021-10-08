#include<bits/stdc++.h>
using namespace std;

int main(){

    string A;
    cin>>A;
    string A_rev;

    for(int i = A.size()-1; i>=0; --i){
        A_rev.push_back(A[i]);
    }
    if(A_rev == A){
        cout<<"Its a Palindrome";
    }
    else{
        cout<<"Not a Palindrome";
    }

    return 0;
}