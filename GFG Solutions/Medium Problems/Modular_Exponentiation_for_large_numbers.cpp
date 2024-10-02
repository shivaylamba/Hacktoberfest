/*
Modular Exponentiation for large numbers
Implement pow(x, n) % M.
In other words, for a given value of x, n, and M, find  (xn) % M.
Example 1:
Input:
x = 3, n = 2, m = 4
Output:
1
Explanation:
32 = 9. 9 % 4 = 1.
Example 2:
Input:
x = 2, n = 6, m = 10
Output:
4
Explanation:
26 = 64. 64 % 10 = 4.
Your Task:
You don't need to read or print anything. Your task is to complete the function PowMod() which takes integers x, n, and M as input parameters and returns xn % M.
Expected Time Complexity: O(log(n))
Expected Space Complexity: O(1)
Constraints:
1 ≤ x, n, M ≤ 109
*/
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int m)
		{
		    // Code here
		   long long int res = 1;
	while(n>0){
		if(n&1){
			res= (1ll*(res)*(x%m))%m;
		}
		x=(1ll*(x)%m*(x%m))%m;
		n=n>>1;	
	}
	return res;
		}
};