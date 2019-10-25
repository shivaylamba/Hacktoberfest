#include<iostream>
using namespace std;
void TowerOfHanoi(int n,char src,char help,char dest){
    if(n==0)
        return;
    TowerOfHanoi(n-1,src,dest,help);
    cout<<"Moving "<<n<<"th disk from "<<src<<" to "<<dest<<"\n";
    TowerOfHanoi(n-1,help,src,dest);
}
int main(){
    int n;
    cin>>n;
    TowerOfHanoi(n,'a','b','c');
    return 0;
}