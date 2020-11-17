#include <iostream>
#include <array>

using namespace std;

void duplicateElementsSorted1(array<int,11> arr, int s)
{
	int dublicate=0;
	for(int i=0;i<s-1;i++)
	{
		if(arr[i]==arr[i+1] && dublicate!=arr[i])
		{
			cout<<arr[i]<<endl;
			dublicate=arr[i];
		}
	}
}

void duplicateElementsSorted2(array<int,11> arr, int s)
{
	for(int i=0;i<s-1;i++)
	{
		if(arr[i]==arr[i+1])
		{
			int j=i+1;
			while(arr[j]==arr[i])
				j++;
			cout<<arr[i]<<" appears "<<j-i<<" times"<<endl;
			i=j-1;
		}
	}
}

void duplicateElementsSorted3(array<int,11> arr, int s, int h)
{
	int arr1[h];
	for(int i=0;i<h;i++)
		arr1[i]=0;
	for(int i=0;i<s;i++)
	{
		arr1[arr[i]]++;
	}
	for(int i=0;i<h;i++)
	{
		if(arr1[i]>1)
			cout<<i<<" appears "<<arr1[i]<<" times"<<endl;
	}
}

void duplicateElementsUnsorted1(array<int,17> arr, int s)
{
	for(int i=0;i<s-1;i++)
	{
		int count=1;
		if(arr[i]!=-1)
		{
			for(int j=i+1;j<s;j++)
			{
				if(arr[i]==arr[j])
				{
					count++;
					arr[j]=-1;
				}
			}
		}
		if(count>1)
		{
			cout<<arr[i]<<" appears "<<count<<" times"<<endl;
		}
	}
}

void duplicateElementsUnsorted2(array<int,17> arr, int s, int h)
{
	int arr1[h];
	for(int i=0;i<h;i++)
		arr1[i]=0;
	for(int i=0;i<s;i++)
	{
		arr1[arr[i]]++;
	}
	for(int i=0;i<h;i++)
	{
		if(arr1[i]>1)
			cout<<i<<" appears "<<arr1[i]<<" times"<<endl;
	}
}

int main()
{
	array<int,11> arr={3,6,8,8,10,12,12,15,15,15,20};
	int s=arr.size();
	duplicateElementsSorted1(arr,s);
	cout<<"\n\n";
	duplicateElementsSorted2(arr,s);
	cout<<"\n\n";
	duplicateElementsSorted3(arr,s,20);
	cout<<"\n\n";
	array<int,17> arr1={3,5,2,4,7,8,2,3,5,6,7,3,6,4,1,9,6};
	int s1=arr1.size();
	duplicateElementsUnsorted1(arr1,s1);
	cout<<"\n\n";
	duplicateElementsUnsorted2(arr1,s1,9);
	return 0;
}
