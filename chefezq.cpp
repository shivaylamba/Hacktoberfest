#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}

int main()
{
	cout<<isPowerOfTwo(1)<<endl;
	cout<<isPowerOfTwo(2)<<endl;
	cout<<isPowerOfTwo(3)<<endl;
	cout<<isPowerOfTwo(4)<<endl;
	cout<<isPowerOfTwo(5)<<endl;
	cout<<isPowerOfTwo(6)<<endl;
	cout<<isPowerOfTwo(7)<<endl;
	cout<<isPowerOfTwo(8)<<endl;
	return 0;
}
