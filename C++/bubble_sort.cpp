//Bubble Sort
#include <bits/stdc++.h>
using namespace std;
int main()
{
//Inputs size of array
cin >> n;
//Inputs the array
for(int i = 0; i < n; i++)
{
	cin >> a[i];
}
for(int i = 0; i < n - 1; i++)
{
	for(int j = 0; j < n - i - 1; j++)
	{
		//for ascending order
		if(a[j] > a[j + 1])
		{
			int t = a[j];
			a[j] = a[j + 1];
			a[j + 1] = t;
		}
	}
}
//Prints the array
for(int i = 0; i < n; i++)
{
	cout << a[i];
}