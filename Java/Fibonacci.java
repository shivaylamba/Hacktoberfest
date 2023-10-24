import java.util.Scanner;
class Fibonacci
{
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        int num1=0, num2=1, num3, i, count;
        System.out.print("Enter a number:");
        count = sc.nextInt();
        System.out.print(num1 + " " +num2); // i=0 and i=1 i.e. num1 and num2 will be printed 

        for(i=2; i<count; ++i)  //loop starts
        {
           num3 = num1 + num2;
           System.out.print(" " + num3);
           num1= num2;
           num2 = num3;
        }
        sc.close();
    }
}
