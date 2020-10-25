#include<iostream>
using namespace std;

void no_of_uniqueBST(int a[], int n)
{
	a[0] = 1;
	a[1] = 1;
	for(int i = 2; i  <= n; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			a[i] += a[j] * a[i-j-1];		
		}
	}
}

int main()
{
	int t, n, a[105];
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < 105; ++i)
		 	a[i] = 0;
		no_of_uniqueBST(a, n);
		cout << a[n] << endl;
	}
	return 0;
}
