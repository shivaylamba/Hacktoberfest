/*
Prompts user for positive number input, then breaks down the number 1 by 1 and displays it in a listed format.
Showing the latest number taken off, and showing the remaining digits.
EXAMPLE:
User inputs: 12345
	digit	number
	5	1234
	4	123
	3	12
	2	1
	1	0
 */

package Practice.Midterm;

import java.util.Scanner;

public class DisplayDigits {

    public static void main(String[] args) {

        // Arrange to use a scanner object for keyboard input
        Scanner scanner = new Scanner(System.in);
        // prompt the user for a positive number

        System.out.print("Enter a positive number" + " and then press Enter: ");
        int number = scanner.nextInt();

        while (number < 0) {
            System.out.println("Ooops, that wasn't a positive number");
            System.out.print("Enter a positive number" + " and then press Enter: ");
            number = scanner.nextInt();
        }

        System.out.println("The number is " + number);
        System.out.println("\tdigit\tnumber");
        while (number > 0) {
            int digit = number % 10;
            System.out.print("\t" + digit);

            number = number / 10;
            System.out.println("\t" + number);
        }

        System.out.println("End of list");
    }
}
