#include<iostream>
using namespace std;

int multiply(int size,int arr[],int m){
	int product,carry=0;
	for(int i=0;i<size;i++){
		product=arr[i]*m+carry;
		carry=product/10;        
		arr[i]=product%10;
	}
	while(carry){             //This loop is to set the last integers of the array
		arr[size]=carry%10;
		carry=carry/10;
		size++;
	}
	return size;
}
int factorial(int N,int arr[]){
   int size=1; arr[0]=1;
   for(int i=1;i<=N;i++) size=multiply(size,arr,i);
   return size;
}

int main(){
	int x[1000],n;
	cout<<"Enter the Number="; cin>>n;
	int size=factorial(n,x);
	cout<<"\nThe facorial is=";
	for(int i=size;i!=0;i--) cout<<x[i-1];
	return 0;
}
