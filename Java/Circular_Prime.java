import java.util.*;
class Q2
{
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Input any number. Numbers <10,000 will take less time to process depending on your processor speed !");
        long n=sc.nextLong();//now this is overkill... long?? Seriously!! o_O
        long t=n;int c=0;int pc=0;int flag=0;
        while(t!=0)
        {
            c++;
            t=t/10;
        }
        long root=(long)Math.pow(10,(c-1));
        for(int x=1;x<=c;x++)
        {
            long fd=n/root;
            long lds=n%root;
            long fc=(lds*10)+fd; pc=0; System.out.print(fc+"  ");
            for(int z=1;z<=fc;z++)
            {
                if(fc%z==0)
                    pc++;
            }
            if(pc==2)
                flag++;
            n=fc;
        }
        if(flag==c)
            System.out.println("Entered number is Circular Prime!");
        else
            System.out.println("Entered number is not Circular Prime!");
        
    }
}