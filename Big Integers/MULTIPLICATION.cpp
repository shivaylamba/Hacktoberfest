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
int main(){
    bool isneg=false;
	int size,temp=0,a,b,MIN,MAX,arr[1000];
	cout<<"Enter First Number="; cin>>a;
	cout<<"Enter Second Number="; cin>>b;
	if(a<0 || b<0){
        if((a<0 && b>0)||(a>0 && b<0)) isneg=true;
        if(b<0) b=b*(-1);
        if(a<0) a=a*(-1);
	}
	else if(a==0 || b==0){
        cout<<"\nThe answer is= 0"<<endl;
        return 0;
	}
	if(a>b){ MIN=b; MAX=a;}
	else{ MIN=a; MAX=b;}
	while(MIN){
		arr[temp]=MIN%10;
		MIN=MIN/10;
		temp++;
	}
	size=multiply(temp,arr,MAX);
	cout<<"\nThe answer is= ";
	if(isneg) cout<<"-";
	for(int i=size;i!=0;i--) cout<<arr[i-1];
	cout<<endl; return 0;
}
