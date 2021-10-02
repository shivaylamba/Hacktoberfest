#include <iostream>
using namespace std;

int main()
{
    int arr[5], n, i, pos;
    i=0;
    while(i<=4)
    {
        cout<<" enter value in element "<<i<<" :";
        cin>>arr[i];
        i++;
        
    }
    pos = 0;
    cout<<" enter any value :";
    cin>>n;
    i=0;
    while(i<=5)
    {
        
        if(n==arr[i])
        {
            
            pos=i+1;
            break;
            
        }
        i++;
        
    }
    if(pos==0)
        cout<<" value not found"<<endl;
    else
        cout<<" Value found at position = "<<pos<<endl;
}