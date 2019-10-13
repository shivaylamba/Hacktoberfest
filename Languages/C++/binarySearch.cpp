//binary search
#include<iostream>
using namespace std;


int binarySearch(int arr[],int l,int r ,int x)
{
	int mid=l+(r-l)/2;
	if(r<l)
	{
		return -1;
	}
	if(arr[mid]==x)
	{
		return mid;
	}
	
	if(arr[mid]>x)
	{
		binarySearch(arr,l,mid-1,x);
	}
	
	else
	{
			binarySearch(arr,mid+1,r,x);
		
	}
	
}



int main()
{
	int input,n;
	
	cout<<"enter the element you want to search\n";
	cin>>input;
	cout<<"enter the size of the array\n";
	cin>>n;
	int arr[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	
	
	int result=binarySearch(arr,0,n-1,input);
	if(result!=-1)
	{
	
	cout<<"the element is found at location "<<result;
	}
	else
	{
		cout<<"element not found";
	}

	
	return 0;
}
