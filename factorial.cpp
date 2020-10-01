#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cout<<"Enter a number: ";
	cin>>n;
	int fact=1;
	for(int i=n;i>=1;i--)
	{
		fact =*i;
	}
	
	cout<<"Factorial of "<<n<<" is "<<fact<<"\n";
	return 0;
}
