import java.util.*;

public class Fib
{
    public static void main(String args[]) 
    {
        int n;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter length of Fibonacci Series : ");
        n=sc.nextInt();
        sc.close();
        int num1=0, num2=1, num3;
        System.out.println("Fibonacci Series");
        for(int i=1; i<=n; i++)  //loop starts
        {
            System.out.print(num1+" ");
            num3 = num1 + num2;
            num1= num2;
            num2 = num3;
        }
    }
}
