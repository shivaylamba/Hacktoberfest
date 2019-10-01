import java.util.Scanner;
import java.lang.*;

public class GCD_recursive {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        int result = GCD(a, b);
        System.out.println("Gcd of a and b is " + result);
    }

    private static int GCD(int a, int b) {
        if (a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }
        if (a == b) {
            return a;
        }

        if (a > b) {
            return GCD(a - b, b);
        } else
            return GCD(a, b - a);
    }
}