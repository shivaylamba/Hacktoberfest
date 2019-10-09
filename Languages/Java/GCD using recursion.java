package Self;

import java.util.Scanner;

public class misc {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		int x = scn.nextInt();
		int y = scn.nextInt();
		System.out.println(gcd(x,y));

	}

	private static int gcd(int a, int b) {

		if (b == 0)
			return a;

		return gcd(b, a % b);

	}
  
  }
