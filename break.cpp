#include <iostream>
using namespace std;
int main(){
    int num;
    int num2;
    cout<<"Enter a Number: ";
    cin>>num;
    cout<<"Enter A number (Devide by) :";
    cin>>num2;
    for(int i=0; i<num; i++){
        if (i%num2==0){
            continue;
        }
        cout<<i<<endl;
    }
}