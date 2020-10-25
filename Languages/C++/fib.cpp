#include<iostream>
#include<cmath>
using namespace std;

long long int lastElement(long long int n)
{
	if(n == 1)
		return 1;
	return 2*lastElement(n/2);
}

int main()
{
	int t;
	
	long long int n, i;
	
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n == 1)
		{
		    cout << 0 << endl;
		    continue;
		}
		long long int l = lastElement(n);
		long long int p=0,q=0,r=0,s=0,j = 1;
		
		if(l == 2)
		    cout << 1 << endl;
		else
		{
		    if(l == 4)
		        cout << 2 << endl;
		    else
		    {
		        while(p <= l || q <= l || r <= l || s <= l)
	    	    {
		         p = pow(2, (4*j-1));
		         q = pow(2, 4*j);
		         r = pow(2,(4*j+1));
		         s = pow(2, (4*j+2));
		        ++j;
		        if(p == l)
		        {
		          cout << 3 << endl;
		         break;
		         }
		        if(q == l)
		        {
		            cout << 0 << endl;
		            break;
		        }
		        if(r == l)
		        {
		            cout << 9 << endl;
		            break;
		        }
		        if(s == l)
		        {
		            cout << 2 << endl;
		            break;
		        }
		        }
		    }
		}
		
	}
}
