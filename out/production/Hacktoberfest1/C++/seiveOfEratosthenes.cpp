//The best algo to find whether a number is prime or not
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void seiveOfEratosthenes(){
    int N,flag=0;
    cin>>N;
    int finalN= sqrt(N);

    std::vector <int> v(finalN);
    for(int i=0;i<v.size();i++){
        v[i]=1;
    }
    v[0]=0;
    v[1]=0;
    for(int i=2;i<v.size();i++){
            if(N%i!=0){
                v[i]=0;
            }
        for(int j=2;j*i<v.size();j++){
            v[i*j]=0;
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i]==1){
            cout<<"not prime";
            cout<<i<<endl;
            flag=1;
            break;

        }
    }
    if(flag==1){
        flag=0;
    }else{
        cout<<"prime";
    }
}

 int main(){
     seiveOfEratosthenes();
    return 0;

 }
