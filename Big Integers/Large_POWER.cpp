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
int power(int a,int N,int arr[]){
   int size=1; arr[0]=1;
   for(int i=1;i<=N;i++) size=multiply(size,arr,a);
   return size;
}
int main(){
    bool isneg=false;
	int x[1000],a,b;
	cout<<"Enter the Number="; cin>>a;
	cout<<"Enter the Power="; cin>>b;
	if(a==0){ cout<<"\nThe answer is= 0"<<endl; return 0;}
	else if(b==0){ cout<<"\nThe answer is= 1"<<endl; return 0;}
	if(a<0 && (b%2!=0)){ isneg=true; a=a*(-1);}
	int size=power(a,b,x);
	cout<<"\nThe answer is= ";
	if(isneg) cout<<"-";
	for(int i=size;i!=0;i--) cout<<x[i-1];
	cout<<endl; return 0;
}
