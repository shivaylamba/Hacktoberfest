import java.util.*;
class Q1
{
    public static  void main(String [] args)
    {
        Random Rand= new Random();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of rows in Array.");
        int m=sc.nextInt();
        System.out.println("Enter the number of columns in Array.");
        int n=sc.nextInt();
        int A[][]=new int[m][n];boolean b=true;long s=0;
        while(b)
        {
            System.out.println("Fill the Array with Random Generated values? \nElse you would have to input each value in the array \nY/N");
            char ch=sc.next().charAt(0);
            switch(ch)
            {
                case 'Y':
                case 'y':    
                  for(int x=0;x<m;x++)
                  {
                    for(int y=0;y<n;y++)
                    {
                        A[x][y]=Rand.nextInt(Integer.MAX_VALUE);//HA! a nifty little trick... B-) 
                    }
                  }
                  b=false;
                  break;
                case 'N':
                case 'n':
                    for(int x=0;x<m;x++)
                    {
                        for(int y=0;y<n;y++)
                        {
                            System.out.println("Enter value for cell at "+x+"*"+y);
                            A[x][y]=sc.nextInt();
                        }
                    }
                    b=false;
                    break;
                default : System.out.println("Come on man! Enter a valid choice!");
            }
        }
        for(int x=0;x<m;x++)
        {
            for(int y=0;y<n;y++)
            {
                int c=0;
                int is=x+y;
                for(int z=1;z<=is;z++)
                {
                    if(is%z==0)
                        c++;
                }
                if(c==2)
                    s=s+A[x][y];
            }
        }
        System.out.println("Sum of all Array Elements having index position(i+j) prime is "+s);
    }
}