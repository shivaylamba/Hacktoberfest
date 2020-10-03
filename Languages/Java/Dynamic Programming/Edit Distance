public class Solution {
public static int minDistance(String a, String b) {

		if (a.length() < b.length()) {
			return minDistance(b, a);
		}

		int[] dp = new int[b.length() + 1];
		int diag = 0, prev = 0;

		for (int i = a.length(); i >= 0; i--) {

			for (int j = b.length(); j >= 0; j--) {

				prev = dp[j];

				if (i == a.length())
					dp[j] = b.length() - j;

				else if (j == b.length())
					dp[j] = a.length() - i;

				else {

					if (a.charAt(i) == b.charAt(j))
						dp[j] = diag;

					else
						dp[j] = Math.min(Math.min(dp[j], dp[j + 1]), diag) + 1;

				}

				diag = prev;
			}

		}

		return dp[0];
	}

}
