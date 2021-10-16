//so you have 15cents.
//and 1 cent=1 choclates
//for Three wrappers you can get 1 choclate
// tell the maximum of choclate can get in 15 cents.


#include<bits/stdc++.h>
using namespace std;

int main(){
int Amount;
cout<<"enter the amount of money you have ";
cin>>Amount;
int wrap=0;
int spent=0;
int choc=0;
for(int i=1;i<=Amount;i++){
    spent=spent-i;
    choc++;
    wrap++;
    if(wrap==3){
        choc=choc+1;
        wrap=1;
    }
}
cout<<choc;

}
