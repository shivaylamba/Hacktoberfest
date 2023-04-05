#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)            
    cin>>a[i];                                   //taking input from the user 


                                                //selection sort algorithm basically finds minimum element and swa-s it with the current element
    for(int i=0;i<n-1;i++)
    {
        int p=i;
        for(int j=i+1;j<n;j++)
        {
             if(a[p]>a[j])
             p=j;
        }
        swap(a[p],a[i]);

    }


    for(int i=0;i<n;i++)                          // printing all the elements of the array as they are sorted
    cout<<a[i]<<" ";

}