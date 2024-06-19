import java.util.Scanner;

public class FindGreatestNumber {
    private int num1, num2, num3;

    public void setInputValues() {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter the first number: ");
            num1 = sc.nextInt();
            System.out.print("Enter the second number: ");
            num2 = sc.nextInt();
            System.out.print("Enter the third number: ");
            num3 = sc.nextInt();
        } catch (Exception e) {
            System.out.println("Invalid input. Please enter valid integers.");
            System.exit(1); // Exit the program on error
        }
    }

    public void findGreatestNumber() {
        int greatest = num1; // Assume num1 is the greatest initially

        if (num2 > greatest) {
            greatest = num2;
        }
        if (num3 > greatest) {
            greatest = num3;
        }

        System.out.println("Greatest number is: " + greatest);
    }

    public static void main(String[] args) {
        System.out.println("Program to Find Greatest Number");

        FindGreatestNumber finder = new FindGreatestNumber();
        finder.setInputValues();
        finder.findGreatestNumber();
    }
}
