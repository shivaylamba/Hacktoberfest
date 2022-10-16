#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;

bool palindrome(string s,int l,int r)
{
   if(l>=r)
       return true;
    else if(s[l]!=s[r])
        return false;
    else
        return palindrome(s,l+1,r-1);
}

int main()
{
    cout<<"Enter a string"<<endl;
    string s;
    cin>>s;
    int l,r;
    cin>>l>>r;
    bool x=palindrome(s,l,r);
    if(x==0)
        cout<<"Not";
    else 
        cout<<"yes";
}
