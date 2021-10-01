package _01_Arrays_and_ArrayLists;

import java.util.Arrays;
import java.util.Scanner;

public class ArrayOfObjects {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        //Array of objects.
        String[] str = new String[5];
        for (int i = 0; i< str.length; i++)
        {
            str[i] = input.next();
        }

        System.out.println(Arrays.toString(str));
    }
}
