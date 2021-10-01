package _01_Arrays_and_ArrayLists;

import java.util.Arrays;
import java.util.Scanner;

public class TwoD_Arrays {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

/*
          *****2D Arrays are like matrices.*****
                          1 2 3
                          4 5 6
                          7 8 9
        Also, 2D arrays are defined with 2 brackets.
*/

        int[][] arr1 = new int[3][]; // Adding the number of rows is mandatory, but adding the number of columns is not.
        //You could store like:
        int[][] ar =
        {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };
        //It can also be like this with variable number of columns.
        int[][] arra =
                {
                        {1, 2, 3},
                        {4, 5},
                        {6, 7, 8, 9, 10}
                };


        //Input 2d array.
        int[][]  ara = new int[3][3];
        for (int i = 0; i< 3; i++)
        {
            for (int j = 0; j< 3; j++)
            {
                ara[i][j] = input.nextInt();
            }
        }

        //if arr is an array, then arr.length() will give the number of rows and arr[rows].length() will give the number of columns.

        System.out.println("Using nested for loops: ");
        for (int row = 0; row< ara.length; row++)
        {
            for (int column = 0; column< ara[row].length; column++)
            {
                System.out.print(ara[row][column] + " ");
            }
            System.out.println();
        }

        System.out.println();

        //Printing using Arrays.toStrings()
        System.out.println("using Arrays.toStrings()");
        for (int rows = 0; rows< 3; rows++)
        {
            System.out.println(Arrays.toString(ara[rows]));
        }

        System.out.println();

        //Printing using enhanced for loop.
        System.out.println("Using enhanced nested for loops: ");
        for (int[] rowElements : ara)
        {
            for (int colElements : rowElements)
            {
                System.out.print(colElements + " ");
            }
            System.out.println();
        }


        System.out.println();

        //Array of strings:
        System.out.println("Enter 4 strings: ");
        String[] stt = new String[4];
        for (int i = 0; i < stt.length; i++)
        {
            stt[i] = input.next();
        }

        System.out.println("Printing array of Strings: ");

        for (String elements : stt)
        {
            System.out.println(elements);
        }
    }
}
