#include<iostream>
using namespace std;
int n;
int part(int* arr,int low,int high)
{
    int pivot;
    pivot = arr[low];
    int i = low +1;
    int j = high;
    while(i<=j)
    {
        while(arr[i] <= pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void Quick_sort(int* arr,int low, int high)
{
    int m;
    if(low<high)
    {
        m = part(arr,low,high);
        Quick_sort(arr,low,m-1);
        Quick_sort(arr,m+1,high);

    }
}
int main()
{
    int *arr,i,j;
    cout<<"Enter the no. of elements: ";
    cin>>n;
    cout<<"Enter the elements:\n";
    arr=new int[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Original array:\n";
    for(i=0;i<n;i++)
    {
       cout<<arr[i]<<" ";
    }

    Quick_sort(arr,0,n-1);
    cout<<"\nSorted array:\n";
    for(i=0;i<n;i++)
    {
       cout<<arr[i]<<" ";
    }
    return 0;
}
