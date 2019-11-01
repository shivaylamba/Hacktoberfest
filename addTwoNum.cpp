#include<iostream>
using namespace std;
int main()
{
	int t, a, b;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		int sum = a;
		int c = b;
		while(c != 0)
		{
			int temp = sum;
			sum = sum^c;
			c = temp&c;
			c = c << 1;
		}
		
		cout << sum << endl;
	}
}
