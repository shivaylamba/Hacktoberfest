#include<bits/stdc++.h>
using namespace std;


int gcdExtended(int a,int b,int *x ,int *y)
{

	if(a == 0)
	{
		*x = 0;
		*y = 1;

		return b;
	}

	int x1,y1;

	int gcd = gcdExtended(b%a,a,&x1,&y1);

	*x = y1 - (b/a) * x1;

	*y = x1;

	return gcd;

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a,b;
	cout<<"enter the numbers to find the gcd of"<<endl;
	cin>>a>>b;

	int x,y;
	int gcd = gcdExtended(a,b,&x,&y);

    cout<<a<<"*"<<x<<"+"<<b<<"*"<<y<<" = "<<gcd;

    cout<<"modulo inverse of a "<< (x%b + b)%b<<endl;
    cout<<"modulo inverse of b "<< (y%a + a)%a;
	return 0;
}

















