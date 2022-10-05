#include <iostream>
using namespace std;

long int catalan(long int n)
{
	if (n <= 1)
		return 1;

	long int result = 0;
	for (int i = 0; i < n; i++)
		result += catalan(i) * catalan(n - i - 1);

	return result;
}

// Driver code
int main()
{
    cout<<"Enter the number of terms of the series : ";
    int ip;
    cin>>ip;
	for (int i = 0; i < ip; i++)
		cout << catalan(i) << " ";
	return 0;
}
