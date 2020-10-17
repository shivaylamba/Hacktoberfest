/**
 * This algorithm is used to swap digits in an integer.
 * Ex: For an input of 1234, it would return 2143
 */

import java.util.*;

public class SwapDigits {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        swapDigits(n);
    }

    public static void swapDigits(int n) {
        char[] c = String.valueOf(n).toCharArray();

        for(int i = 0; i < c.length-1; i+=2) {
            char tmp = c[i];
            c[i] = c[i+1];
            c[i+1] = tmp;
        }
        n = Integer.parseInt(new String(c));
        System.out.println(n);
    }
}
