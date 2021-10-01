import java.util.*;
class Q3
{
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Input any number !");
        int n = sc.nextInt();
        System.out.println("Input = "+n);
        int t = n;
        int s = 0;
        System.out.print("Output = "+n);
        while(s!=1)
        {
            if((t%2)==0)
                s=t/2;
            else
                s=(t*3)+1;
            System.out.print(", "+s);
            t=s;
        }
    }//MAN this is too easy for 10th standard !!
}