#include<bits/stdc++.h>
using namespace std;

// Returns LCS s1 and s2
string lcs(string &s1, string &s2)
{
	int m = s1.length();
	int n = s2.length();

	int dp[m+1][n+1];

	/* Following steps build dp[m+1][n+1] in bottom
	up fashion. Note that dp[i][j] contains
	length of LCS of s1[0..i-1] and s2[0..j-1] */
	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=n; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	// Following code is used to print LCS
	int index = dp[m][n];

	// Create a string length index+1 and
	// fill it with \0
	string lcs(index+1, '\0');

	// Start from the right-most-bottom-most
	// corner and one by one store characters
	// in lcs[]
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		// If current character in s1 and s2
		// are same, then current character
		// is part of LCS
		if (s1[i-1] == s2[j-1])
		{
			// Put current character in result
			lcs[index-1] = s1[i-1];
			i--;
			j--;

			// reduce values of i, j and index
			index--;
		}

		// If not same, then find the larger of
		// two and go in the direction of larger
		// value
		else if (dp[i-1][j] > dp[i][j-1])
			i--;
		else
			j--;
	}

	return lcs;
}

// Returns longest palindromic subsequence
// of str
string longestPalSubsequence(string &str)
{
	// Find reverse of str
	string rev = str;
	reverse(rev.begin(), rev.end());

	// Return LCS of str and its reverse
	return lcs(str, rev);
}

/* Driver program to test above function */
int main()
{
	string s;
	cin>>s;//Enter string

	cout << longestPalSubsequence(s);
	return 0;
}
