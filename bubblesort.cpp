#include <iostream>
using namespace std;

int main()
{
	int a[5];
	int temp;
	for(int i=0;i<5;i++)
	{
		cin>>a[i];
	}
	
	for(int j=0;j<4;j++)
	{
		for(int k=j+1;k<5;k++)
			if(a[j]>a[k])
			{
				temp=a[k];
				a[k]=a[j];
				a[j]=temp;
			}
	}
	
	cout<<"the elements after sorting"<<endl;
	for(int i=0;i<5;i++)
		cout<<a[i]<<endl;
	
	return 0;
}
