// Checks if a given string str is palindrome or not

#include <iostream>
#include<string.h>
using namespace std;

int main() {
	cout<<"Enter the string: ";
	string str;
	cin>>str;
	bool palin=true;
	int n=str.length();
	for(int i=0;i<n/2;i++){
	    if(str[i]!=str[n-i-1]){
	        palin=false;
	        break;
	    }
	}
	if(palin==true)
	cout<<" Palindrome\n";
	else
	cout<<"Not Palindrome\n";
	return 0;
}
