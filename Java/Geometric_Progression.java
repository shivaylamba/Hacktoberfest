import java.util.*;
class Q5
{
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter base number (a)");
        int a=sc.nextInt();
        System.out.println("Enter progression factor(r)");
        int r=sc.nextInt();
        for(int x=0;x<10;x++)
        {
            System.out.print((a*Math.pow(r,x))+", ");//Single statement that makes the mark...YO!
        }
    }
}