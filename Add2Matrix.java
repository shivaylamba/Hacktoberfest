package introduction;

import java.util.Scanner;

public class Add2Matrix {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the dimensions");
		int row = sc.nextInt();
		int col = sc.nextInt();
		
		int[][] a = new int[row][col];
		int[][] b = new int[row][col];
		int[][] c = new int[row][col];
		
		System.out.println("Enter the elements of a :");
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				a[i][j] = sc.nextInt();
			}
		}
		
		System.out.println("Enter the elements of b :");
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				b[i][j] = sc.nextInt();
			}
		}
		
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				c[i][j] = a[i][j] + b[i][j];
			}
		}
		
		System.out.println("The matrix c is ");
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				System.out.print(c[i][j] + " ");
			}
			System.out.println();
		}
		
	}

}
