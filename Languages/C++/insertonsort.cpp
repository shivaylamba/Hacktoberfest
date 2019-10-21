#include<iostream>
using namespace std;
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {

            if(a[i]<a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                i=j;
            }

        }


    }
     for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
return 0;
}
