// Program to generate an array having its ith element equals to the product of elements in the given array except the ith number in the given array
// For example input array=[1, 2, 3, 4],  output will be= [24, 12, 8, 6]

// The speciality in this program is 
//    1. It does not uses division mechanism to compute as it will be easy with division.
//    2. The time complexity is O(n).  
#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n, p, i;
	cout<<"Enter no of elements"<<endl;
	cin>>n;
	vector<int>v;
	vector<int>left;
	int right[n], output[n];
	int prod=1;
	for(i=0;i<n;i++){
		cin>>p;
		v.push_back(p);
		prod=prod*p;
		left.push_back(prod);
	}
	prod=1;
	for(i=n-1;i>=0;i--){
		prod=prod*v[i];
		right[i]=prod;
	}
	for(i=1;i<n-1;i++){
		output[i]=left[i-1]*right[i+1];
	}
	output[0]=right[1];
	output[n-1]=left[n-2];
	for(i=0;i<n;i++){
		cout<<output[i]<<" ";
	}
	return 0;
}
