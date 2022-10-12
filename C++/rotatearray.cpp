//contributed by ISHITA SINGHAL

/* PROBLEM STATEMENT
You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
*/




#include <iostream>
using namespace std;
void rotate(int *input, int d, int n)
{
    
    int tmp[n];
    for (int i=0;i<n;i++){
      tmp[i]=input[i];
    }
    int size=n;
    for (int i=0;i<n;i++){
        input[i]=tmp[(i+d)%size];
    }
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}
