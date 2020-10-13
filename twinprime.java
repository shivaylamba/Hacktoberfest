import java.util.Scanner;
class twinprime
{
    public boolean prime(int a)
    {
        int count=0;
        for(int x=2;x<=(int)Math.sqrt(a);x++)
        {
            if(a%x==0)
            count++;
            
        }
        if(count==0&&a!=1)
        return true;
        else
        return false;
    }
     public static void main(String[]args)
     {
         Scanner sc=new Scanner(System.in);
         twinprime obj=new twinprime();
         System.out.println("Enter the limit");
         int n=sc.nextInt();
         for(int x=1;x<n;x++)
         {
             boolean b=obj.prime(x);
             boolean c=obj.prime(x+2);
             if(b==true&&c==true)
             System.out.println(x+" "+(x+2));
            }
        }
    }



