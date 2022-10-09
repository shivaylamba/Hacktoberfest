#include<iostream>
using namespace std;
int main()
{
	
	int i,j,r,a[100];

	cout<<"Enter number of elements\n";

	cin>>r;

	for(i=0;i<r;i++)
	{
		
		cin>> a[i];

	}

	for(i=0;i<r-1;i++)
	{
		for(j=0;j<r-1-i;j++)
		{
			if(a[j]>a[j+1])
			{	int t;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}


	cout<<"Sorted array:\n";

	for(i=0;i<r;i++)
	{
		cout<< a[i];
	}
}
