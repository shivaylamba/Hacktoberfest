public class FibonacciDP {

    public static long fibonacci(int n) {
        if (n <= 1) {
            return n;
        }
        
        // Create an array to store Fibonacci numbers
        long[] fib = new long[n + 1];
        
        // Base cases
        fib[0] = 0;
        fib[1] = 1;
        
        // Calculate and store Fibonacci numbers iteratively
        for (int i = 2; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        
        return fib[n];
    }

    public static void main(String[] args) {
        int n = 10; // Example: Calculate Fibonacci number at index 10
        System.out.println("Fibonacci number at index " + n + " is: " + fibonacci(n));
    }
}
