import java.util.* ;
public class EuclidsGcd{

    static long gcd(long a, long b){
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in) ;
        System.out.println("Enter two numbers to find gcd");
        long x = in.nextLong() ;
        long y = in.nextLong() ;
        System.out.println(gcd(x,y)) ;
    }
}
