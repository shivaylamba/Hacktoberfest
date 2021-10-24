/*
Given a 'value', we have to find the number of ways to make change for 'value' cents, 
if we have infinite supply of each of Si (1<= i<= N) valued coins.
*/
#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int>& arr, int val, int n, vector<vector<int>>& T)
{
	if (val == 0)
		return T[n][val] = 1;
	if (n == 0)
		return 0;
	if (T[n][val] != -1)
		return T[n][val];
	if (arr[n - 1] <= val) {
		return T[n][val] = coinChange(arr, val - arr[n - 1], n, T) + coinChange(arr, val, n - 1, T);
	}
	else 
		return T[n][val] = coinChange(arr, val, n - 1, T);
}
int main()
{
	int n=4;
	int value=10;
	vector<int> S = { 2, 5, 3, 6 };
	vector<vector<int>> T(n + 1, vector<int>(value + 1, -1)); //2d vector
	int result = coinChange(S, value, n, T);
	cout<<result<<endl;
}
