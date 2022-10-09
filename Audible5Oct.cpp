#include<iostream>
using namespace std;

int main(){
    int testcase;
	cin>>testcase;
	
	while(testcase--){
		
		int input;
		cin>>input;
		
		if(input >= 67 && input <= 45000)
        {
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
    	return 0;
}