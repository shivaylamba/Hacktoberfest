/**
 * This is a algorithm to implement the Fibonacci Nth element problem
 * using dynamic programming paradigm. This version I am using the memoization
 * strategy to going top-down to find all needed values and store on the fiboMemo array.
 *
 * @author Sivaram Rasathurai
 */

public class Fibonacci {

    private int[] fiboMemo;

    private int findNthElement(int n) {

        if (this.fiboMemo == null) {
            fiboMemo = new int[n + 1];
        }

        if (n <= 1) {
            fiboMemo[n] = n;
        } else {
            fiboMemo[n] = findNthElement(n - 1) + findNthElement(n - 2);
        }

        return fiboMemo[n];
    }

    /**
     * Tests the function to the given number passed as argument
     * @param args
     */
    public static void main(String[] args) {
        try {
            int arg = Integer.parseInt(args[0]);
            System.out.println(new Fibonacci().findNthElement(arg));
        } catch (Exception e) {
            System.out.println("The argument entered is not a valid integer number.");
        }
    }
}