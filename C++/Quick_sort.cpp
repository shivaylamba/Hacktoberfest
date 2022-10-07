#include<iostream>
using namespace std;
// For swapping the values
void swap(int*x, int *y)
{                                                        
    int *temp=x;
    x=y;
    y=temp;
}
// For finding the partion value
int partion(int arr[], int l, int h)
{
    int pivot=arr[l];
    int start=l;
    int end=h;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[l], arr[end]);
    return end;

}
// for quick sort 
void quick_sort(int arr[],int l, int h)
{
    if(l<h)
    {
        int pos=partion(arr, l,h);
        quick_sort(arr,l,pos-1);
        quick_sort(arr,pos+1,h);
    }
}
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int arr[n];
    cout<<" Enter the elements in array :";          // inputing the array
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    quick_sort(arr,0,n-1);
     cout<<" The sorted  elements in array :";          // outputing the array
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}