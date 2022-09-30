#include<iostream>
using namespace std;
int main()
{
    int max,min,i,n,s;
    cout<<"the size of array"<<endl;
    cin>>n;
     int arr[n];
     cout<<"enter elements in an array"<<endl;
     for(i=0;i<n;i++)
     {
        cin>>arr[i];

     }
     max=arr[0];
     min=arr[0];
     for(i=0;i<n;i++)
     {
        
        if(arr[i]>max)
        max=arr[i];
        if(arr[i]<min)
        min=arr[i];
     }
     /*s=max-min;
     cout<<"max distance is"<<endl<<s<<endl;*/

     cout<<"max and min are"<<endl<<max<<endl<<min<<endl;
}
     