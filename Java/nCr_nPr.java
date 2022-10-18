import java.util.*;

public class nCr_nPr {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Type n and r: ");
		int n = sc.nextInt();
		int r = sc.nextInt();
		System.out.println("nCr value is: " + nCr(n, r) + " nPr value is: " + nPr(n, r));
		sc.close();
	}

	public static double nCr(int n, int r) {
		return fact(n) / (fact(r) * fact(n - r));
	}

	public static double nPr(int n, int r) {
		return fact(n) / fact(n - r);
	}

	public static long fact(int n) {

		long f = 1;

		for (int i = 1; i <= n; i++) {
			f *= i;
		}

		return f;

	}
}