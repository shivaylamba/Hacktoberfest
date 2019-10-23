package Self;

import java.util.Scanner;

public class misc {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		
		TOH(scn.nextInt(), 'A', 'B', 'C');

	}

	public static void TOH(int n, char src, char dst, char help) {

		if (n == 0) {
			return;
		}

		TOH(n - 1, src, help, dst);
		System.out.println("Moving ring " + n + " from " + src + " to " + dst);
		TOH(n - 1, help, dst, src);

	}

}

