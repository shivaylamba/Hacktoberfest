//Chef Wars - Return of the Jedi
//An August Challenge 2020 problem
//Author:aryanag_adm

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int T;
    cin>>T;
    while(T--)
    {
        double H,P;
        cin>>H>>P;
        while(H>0 && P>0)
        {
            H-=P;
            P/=2.0;
            P=floor(P);
            
        }
        if(H>0)
            cout<<"0\n";
        else
            cout<<"1\n";
    }
    return 0;
}

