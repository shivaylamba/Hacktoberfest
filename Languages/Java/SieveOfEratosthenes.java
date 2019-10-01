
import java.util.Scanner;
import java.lang.*;

public class SieveOfEratosthenes {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number upto which you need prime numbers");
        int n = scanner.nextInt();
        System.out.println("Prime numbers upto " + n + " are ");
        SievePrime(n);
    }

    private static void SievePrime(int n) {
        // boolean array of n+1 size for storing (0..n) values.
        Boolean[] arr = new Boolean[n + 1];
        // initialize every element of arr to true. AS true element will be prime.
        for (int i = 0; i < n; i++) {
            arr[i] = true;
        }

        //initially first p will start from 2
        for (int p = 2; p * p < n; p++) {

            // if arr[p] is not changed then it is prime.
            if (arr[p]) {

                //Update all multiples of p
                for (int i = p * p; i <= n; i += p) {
                    arr[i] = false;
                }
            }
        }

        // print all prime numbers.
        for (int i = 2; i <= n; i++) {
            if (arr[i]) {
                System.out.print(i + " ");
            }
        }
    }
}