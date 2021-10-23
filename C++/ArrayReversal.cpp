#include<iostream>
using namespace std;
void reverse(int arr[],int size)
{
for(int i=0; i<size/2; i++)
{
int temp=arr[i];
arr[i]=arr[size-i-1];
arr[size-i-1]=temp;
}
}
int main()
{
int size;
cout<<"Enter size of array"<<"\n";
cin>>size;
int arr[size];
for(int i=0;i<size;i++)
{
cin>>arr[i];
}
cout<<"\n";
reverse(arr,size);
for(int i:arr)
cout<<i<<"\t";
}