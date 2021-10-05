#include<iostream.h>
using namespace std;

int main()
{
    int x,first=0,second=1,i,y[100];
    cout<<"ENTER THE NUMBER OF TERMS: ";
    cin>>x;
    cout<<first<<endl;
    cout<<second<<endl;
    y[0]=first;
    y[1]=second;

    for(i=2;i<x;i++)
    {
        y[i]=y[i-1]+y[i-2];
        cout<<y[i]<<endl;
    }

}