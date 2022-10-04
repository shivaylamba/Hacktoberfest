//Input:12 11 13 5 6 7
//Output:
#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while (i<n1&&j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k++]=a[i++];
        }
        else
        {
            arr[k++] = b[j++];
        }
    }
    while(i<n1)
    {
        arr[k++]=a[i++];
    }
    while (j < n2)
    {
        arr[k++] = b[j++];
    }
}
void mergeSrt(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergeSrt(arr,l,mid);
        mergeSrt(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the array size:";
    cin>>n;
    int arr[n];
    cout<<"Enter the values:";
    for(int i=0;i<n;i++)
    {
       cin>>arr[i];
    }
    mergeSrt(arr,0,n-1);
    cout<<"Displaying the array after sorting:";
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<" ";
    }
    return 0;
}