import java.util.Scanner;

public class factorial {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = sc.nextInt();
        sc.close();
        int a = fac(i);
        System.out.println(a);
    }

    static int fac(int num) {
        if (num < 1) {
            return 1;
        } else
            return num * fac(num - 1);

    }
}