//Nth Root Of M
//        Problem Statement:  Given two numbers N and M, find the Nth root of M.
//        The nth root of a number M is defined as a number X when raised to the power N equals M.
//        Example 1:
//        Input: N=3 M=27
//        Output: 3
//        Explanation: The cube root of 27 is 3.
//        Example 2:
//        Input: N=2 M=16
//        Output: 4
//        Explanation: The square root of 16 is 4

public class FindNthRootOfNumber {
    public static double findNthRootOfM(int n, int m) {
        // Write your code here.
        double low = 1;
        double high = m;
        double eps = 1e-6;

        while((high - low ) > eps){
            double mid = (high + low) /2;

            if( multiply(mid, n) < m){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return low;
    }

    public static double multiply(double number, int n) {
        double ans = 1.0;
        for(int i = 1;i<=n;i++) {
            ans = ans * number;
        }
        return ans;
    }
    public static void main (String[] args) {
        int n = 3, m = 27;
        System.out.println(n + " root of " + m +" is " +findNthRootOfM(n, m));
    }
}