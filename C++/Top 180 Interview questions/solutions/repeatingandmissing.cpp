#include <bits/stdc++.h>
using namespace std;
void getTwoElements(int arr[], int n,
					int* x, int* y)
{
	int xor1;
	// xor of any number with 0 is the number itself
	int set_bit_no;
	to calculate the rightmost set bit striver video
	int i;
	int x=0;
	int y=0;

	xor1 = arr[0];

	/* Get the xor of all array elements */
	for (i = 1; i < n; i++)
		xor1 = xor1 ^ arr[i];

	/* XOR the previous result with numbers
	from 1 to n*/
	for (i = 1; i <= n; i++)
		xor1 = xor1 ^ i;

	/* Get the rightmost set bit in set_bit_no */
	set_bit_no = xor1 & ~(xor1 - 1);

	// dividing the elements in two sets
	for (i = 0; i < n; i++) {
		if (arr[i] & set_bit_no)
			/* arr[i] belongs to first set */
			x = x ^ arr[i];

		else
			/* arr[i] belongs to second set*/
			y = y ^ arr[i];
	}
	for (i = 1; i <= n; i++) {
		if (i & set_bit_no)
			/* i belongs to first set */
			x = x ^ i;

		else
			/* i belongs to second set*/
			y = y ^ i;
	}

	/* *x and *y hold the desired
		output elements */
	// x can be the missing element and y can be the repeating element.
}

int main()
{
	int arr[] = { 1, 3, 4, 5, 5, 6, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	getTwoElements(arr, n);
}
