import java.util.Arrays;

public class DPDemos {

	public static void main(String[] args) {

		String s1 = "abcdjcxhvjkdf j,vhdk";
		String s2 = "agcfd jdb fjehviu";
		System.out.println(LCS(s1, s2));
		System.out.println(LCSTD(s1, s2, new int[s1.length() + 1][s2.length() + 1]));
		System.out.println(LCSBU(s1, s2));

	}

	public static int LCSTD(String s1, String s2, int[][] strg) {

		if (s1.length() == 0 || s2.length() == 0) {
			return 0;
		}

		if (strg[s1.length()][s2.length()] != 0) {
			return strg[s1.length()][s2.length()];
		}

		char ch1 = s1.charAt(0);
		char ch2 = s2.charAt(0);

		String ros1 = s1.substring(1);
		String ros2 = s2.substring(1);

		int ans = 0;

		if (ch1 == ch2) {
			ans = LCSTD(ros1, ros2, strg) + 1;
		} else {
			int c1 = LCSTD(ros1, s2, strg);
			int c2 = LCSTD(s1, ros2, strg);

			ans = Math.max(c1, c2);

		}

		strg[s1.length()][s2.length()] = ans;
		return ans;

	}

	public static int LCSBU(String s1, String s2) {

		int[][] strg = new int[s1.length() + 1][s2.length() + 1];

		for (int row = s1.length() - 1; row >= 0; row--) {

			for (int col = s2.length() - 1; col >= 0; col--) {

				if (s1.charAt(row) == s2.charAt(col)) {
					strg[row][col] = 1 + strg[row + 1][col + 1];
				} else {
					int c1 = strg[row + 1][col];
					int c2 = strg[row][col + 1];

					strg[row][col] = Math.max(c1, c2);
				}
			}
		}

		return strg[0][0];

	}

}