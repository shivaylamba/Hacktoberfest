#include<iostream>
using namespace std;

template<class T>
int lin_search(T arr[20],int x,int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
		    return i+1;
		}
	}
	return -1;
}

template<class T>
int bin_search(T arr[20],int x,int n)
{
	
	int high,mid,low;
	high=n-1;
	low=0;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(x==arr[mid])
		{
			return mid+1;
		}
		else if(x>arr[mid])
		{
		    low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	return -1;
}


int main()
{
	int n,choice,x,l,b,arr[20];
	char ch='y';
	while(ch=='y'||ch=='Y')
	{
		cout<<"*****Main Menu*****"<<endl;
		cout<<"1. Enter the array : "<<endl;
		cout<<"2. Searching element : "<<endl;
		cout<<"3. Linear Search : "<<endl;
		cout<<"4. Binary Search : "<<endl;
		cout<<"5. Exit : "<<endl;
		cout<<" Enter your Choice[1-5] : ";
		cin>>choice;
		switch(choice)
		{
			case 1 : cout<<"Enter the total number of elements you want : "<<endl;
			         cin>>n;
			         cout<<"Enter the elements of array : ";
			         for(int i=0;i<n;i++)
			         {
			         	cin>>arr[i];
					 } 
			         break;
			case 2 : cout<<"2. Enter the element to be searched : "<<endl;
			         cin>>x;
					 break;	    
			case 3 : l=lin_search(arr,x,n);
			         if(l==-1)
			         	cout<<"Element not found"<<endl;
			         else
					    cout<<"Element found at position "<<l<<endl;	
			         break;
			case 4 : b=bin_search(arr,x,n);
			         if(b==-1)
			         	cout<<"Element not found"<<endl;
			         else
					    cout<<"Element found at position "<<b<<endl;	
			         break;
			case 5 : exit(0);         
			default: cout<<"Error in Input!!"<<endl;
			         break;		 		 		  
		}
		cout<<"\nDo you want to Continue : ";
		cin>>ch;
	        }
	}

