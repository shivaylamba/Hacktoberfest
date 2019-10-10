package Java;

import java.lang.*;
import java.util.Scanner;

public class GCD {

//     This is a program to calculate GCD that is greatest common divisor of two numbers. 
//     It is also called HCF that is Highest Common Factor.
// Eg GCD of 4 and 6 is 2 as 2 is largest number that divides both 4 and 6
    
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        int divident = scn.nextInt();
        int divisor = scn.nextInt();

        while (divident % divisor != 0) {

            int rem = divident % divisor;

            divident = divisor;
            divisor = rem;
        }
        System.out.println(divisor);
    }
}
