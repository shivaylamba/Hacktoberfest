#include <bits/stdc++.h> //header file that includes every standard library
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of the array you want to input: "<<endl;
	cin>>n;
	vector<int> arr(n);
	cout<<"Enter Values of your array: "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cout<<"Enter number you want to search in the array "<<endl;
	cin>>k;
	int flag = -1; //to check if element present and check index
	//checking for values
	for(int i=0;i<n;i++){
		if(k==arr[i]){
			flag = i;//found it
			break;//break out of loop since number found
		}
	}
	
	if(flag!=-1){
		cout<<"The number is placed at index "<<flag<<endl;
	}else{
		cout<<"The number "<<k<<" not found"<<endl;
	}
}
