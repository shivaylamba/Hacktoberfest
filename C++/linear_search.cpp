#include <iostream>
using namespace std;
int main()
{
    int t,n;
    cout<<"Enter number of elements in array\n";
    cin>>n;
    int a[n];
    cout<<"Enter elements of array\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"Enter element to search\n";
    cin>>t;
    int pos=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==t)
        {
            pos=i+1;
            break;
        }
    }
    if(pos==-1)
    cout<<t<<" not present in given array";
    else
    cout<<t<<" present in array at position:"<<pos;
    return 0;
}

