/*file: MatrixMultiplication.java
 * author: Naveen
 */

import java.util.Scanner;
public class MatrixMultiplication {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int mat1[][],mat2[][],mat3[][],r1,r2,c1,c2;
		
		System.out.println("Enter the number of rows in matrix1:");
		r1=in.nextInt();
		System.out.println("Enter the number of columns in matrix1:");
		c1=in.nextInt();
		mat1=new int[r1][c1];
		System.out.println("Enter the matrix elements:");
		for(int i=0;i<r1;i++)
		{
			for(int j=0;j<c1;j++)
			{
				mat1[i][j]=in.nextInt();
			}
		}
		
		System.out.println("\nEnter the number of rows in matrix2:");
		r2=in.nextInt();
		System.out.println("Enter the number of columns in matrix2:");
		c2=in.nextInt();
		mat2=new int[r2][c2];
		System.out.println("Enter the matrix elements:");
		for(int i=0;i<r2;i++)
		{
			for(int j=0;j<c2;j++)
			{
				mat2[i][j]=in.nextInt();
			}
		}
		
		if(c1!=r2)
		{
			System.out.println("\nMatrix cannot be multiplied");		
		}
		else
		{
			System.out.println("\nResultant Matrix:");
			mat3=new int[r1][c2];
			for(int i=0;i<r1;i++)
			{
				for(int j=0;j<c2;j++)
				{
					mat3[i][j]=0;
					for(int k=0;k<r2;k++)
					{
						mat3[i][j]+=mat1[i][k]*mat2[k][j];
					}
					System.out.print(mat3[i][j]+"\t");
				}
				System.out.println();
			}
		}
	}

}
