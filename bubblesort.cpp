#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void bubble_sort(int arr[], int n){
	for(int i=0;i<n-1;i++){
		cout<<" Iteration: "<<i<<endl;
		int swa=0;
	for(int j=0;j<n-i-1;j++){

		if(arr[j]>arr[j+1]){
			cout<<"SWappiing :"<<arr[j]<<" "<<arr[j+1]<<endl;
			swap(arr[j],arr[j+1]);
			swa++;
		}
	}
		if(swa==0){
			break;
		}	
	}
}


int main(){
	int arr[10];
	int n;
	cout<<"Enter the number of elements :";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bubble_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
	return 0;
}
