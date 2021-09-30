#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout << "Enter the size of array" << endl;
	cin >> n;
	vector<int> arr(n);
	cout << "Enter array" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int key;
	cout << "Enter the key to be searched: " << endl;
	cin >> key;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == key)
		{
			cout << "Key found at " << i << " index" << endl;
			return 0;
		}
	}
	cout << "Key not found" << endl;
	return 0;
}
