import java.util.*;
class Q6
{
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number under which Primes will be counted!");
        int n=sc.nextInt();int counter=0;int c=0;
        for(int x=1;x<=n;x++)
        {
            c=0;
            for(int y=1;y<=x;y++)
            {
                if(x%y==0)
                    c++;
            }
            if(c==2)
                counter++;
        }
        System.out.println("Number of Primes under "+n+" is "+counter);
    }
}