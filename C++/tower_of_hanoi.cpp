/* Author : VANSH KAPILA */

/* "The greatest glory in living lies not in never falling, but in rising every time we fall." -*/

#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define int long long
#define ld long double
#define endl "\n";

#define f(a,b) for(int i=a;i<b;i++)
#define fr(a,b) for(int i=a;i>b;i--)

const int mod = 1000000007;
using namespace std;

void hanoi(int n, char str, char helper, char dest)
{
	if (n == 1)
	{	cout << "Moving ring " << n << " from " << str << " to " << dest << endl;
		return;
	}

	hanoi(n - 1, str, dest, helper);
	cout << "Moving ring " << n << " from " << str << " to " << dest << endl;
	hanoi(n - 1, helper, str, dest);
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int str = 0;
		int helper = 0;
		int dest = 0;
		hanoi(n, 'A', 'C', 'B');



	}
	return 0;
}