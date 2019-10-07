#include<iostream>
using namespace std;
void sort(int a[],int size)
{
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1-i;j++)
			{
				if(a[j]>=a[j+1])
				{
					int t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
	}
}
int main()
{
	int n;
	cout<<"Enter Size of Array:";
	cin>>n;
	int a[n];
	cout<<"Enter Elements:";
	for(int p=0;p<n;p++)
		cin>>a[p];
	sort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<"  ";
}
