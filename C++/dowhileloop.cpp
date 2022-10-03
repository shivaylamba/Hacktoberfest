###A simple code example to show how to use do while loop

//in this example we are printing a table of 7

#include<iostream>
using namespace std;
int main(){
    int i=1,n=7;
    do{
        cout<<i<<"*"<<n<<"="<<i*n<<endl;
        i++;
    }while(i<=10);
    return 0;
}
