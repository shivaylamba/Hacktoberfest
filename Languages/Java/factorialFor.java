import java.util.*;
public class factorialFor{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number, factorial, i;
        System.out.print("Enter the number: ");
        number = input.nextInt();

        factorial = 1;
        for (i = 1; i <= number; i++){
            factorial = factorial * i;
        }
         System.out.printf("The factorial of %d is %d\n", number, factorial);   
    }
}