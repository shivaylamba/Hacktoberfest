#include<iostream>
using namespace std;

int main(){
	int a[10],size,num,pos;
	cout<<"Enter the size of array"<<endl;
	cin>>size;
	cout<<"Enter elements: "<<endl;
	for(int i =0;i<size;i++)
	{
		cin>>a[i];
	}
	cout<<endl<<"Enter the data or num you want to enter: "<<endl;
	cin>>num;
	cout<<"enter the position: "<<endl;
    cin>>pos;

	for(int i=size-1; i>=pos-1; i--)
	{
		a[i+1]=a[i];
	}
	a[pos-1]=num;
	size++;

	cout<<"After inserting the element at pos(index=pos-1)"<<endl;
	for(int i = 0;i<size;i++){
		cout<<a[i]<<" ";
	}

	return 0;
}
