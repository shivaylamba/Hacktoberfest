package _01_Arrays_and_ArrayLists;

import java.util.Arrays;
import java.util.Scanner;

public class Java_Input {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int[] arr = new int[5];
        //input using for loops.
        System.out.println("Enter 5 elements: ");
        for (int i = 0; i < arr.length; i++)
        {
            arr[i] = input.nextInt();
        }

        System.out.println();

        //printing an array for using loops.
        System.out.println("Using normal for loop:");
        for (int i = 0; i < arr.length; i++)
        {
            System.out.print(arr[i] + " ");
        }

        System.out.println();
        System.out.println();

        //printing an array with enhanced for loop.
        System.out.println("Now using for each loop: ");
        for (int element : arr) // for each element of the array
        {
            System.out.print(element + " "); // print the element of the array.
        }

        System.out.println();
        System.out.println();

        //Printing an array using Arrays.toString() which converts the array into a String, adding the brackets and commas and then prints it.
        System.out.println("Using toString(): ");
        System.out.println(Arrays.toString(arr));

    }
}
