// C++ program to find minimum step to delete a string
#include <bits/stdc++.h>
using namespace std;

/* method returns minimum step for deleting the string,
where in one step a palindrome is removed */
int minStepToDeleteString(string str)
{
	int N = str.length();

	// declare dp array and initialize it with 0s
	int dp[N + 1][N + 1];
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			dp[i][j] = 0;

	// loop for substring length we are considering
	for (int len = 1; len <= N; len++)
	{
		// loop with two variables i and j, denoting
		// starting and ending of substrings
		for (int i = 0, j = len - 1; j < N; i++, j++)
		{
			// If substring length is 1, then 1 step
			// will be needed
			if (len == 1)
				dp[i][j] = 1;
			else
			{
				// delete the ith char individually
				// and assign result for subproblem (i+1,j)
				dp[i][j] = 1 + dp[i + 1][j];

				// if current and next char are same,
				// choose min from current and subproblem
				// (i+2,j)
				if (str[i] == str[i + 1])
					dp[i][j] = min(1 + dp[i + 2][j], dp[i][j]);

				/* loop over all right characters and suppose
					Kth char is same as ith character then
					choose minimum from current and two
					substring after ignoring ith and Kth char */
				for (int K = i + 2; K <= j; K++)
					if (str[i] == str[K])
						dp[i][j] = min(dp[i+1][K-1] + dp[K+1][j],
													dp[i][j]);
			}
		}
	}

	/* Uncomment below snippet to print actual dp tablex
	for (int i = 0; i < N; i++, cout << endl)
		for (int j = 0; j < N; j++)
			cout << dp[i][j] << " "; */

	return dp[0][N - 1];
}

// Driver code to test above methods
int main()
{
	string str = "2553432";
	cout << minStepToDeleteString(str) << endl;
	return 0;
}
