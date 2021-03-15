#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cout<<"enter the coefficient of x^2 \t";
	cin>>a;
	cout<<"enter the coefficient of x \t ";
	cin>>b;
	cout<<"enter the constant ";
	cin>>c;
	float dis=(b*b-4*a*c);
	//cout<<dis;
	float root1=0,root2=0;
	if (dis<0)
		cout<<"no roots exists";
	else
	{
		root1=(-b)/(2.0*a) +sqrt(dis)/2.0*a;
		root2=(-b)/(2.0*a) -sqrt(dis)/(2.0*a);
	
	cout<<"first root is"<<root1;
	cout<<"second root is"<<root2;
	}
	return 0;
}
