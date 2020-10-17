class Printer
{
    boolean isOdd = true;
    
    synchronized void print(int num)
    {
        if(num%2!=0)
        {
            while(!isOdd)
            {
                try
                {
                    wait();
                }
                catch(InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
            System.out.print(num+" ");
        }
        else
        {
            while(isOdd)
            {
                try
                {
                    wait();
                }
                catch(InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
            System.out.print(num+" ");
        }
        isOdd = !isOdd;
        notifyAll();
    }
}

class Custom extends Thread
{
    boolean isEven;
    int max;
    Printer p;
    Custom(boolean isEven, int max, Printer p)
    {
        this.isEven = isEven;
        this.max = max;
        this.p = p;
    }
    
    public void run()
    {
        for(int i=this.isEven?2:1; i<=this.max; i+=2)
            this.p.print(i);
    }
}

public class MultiThreading 
{
    static void util(int n)
    {
        Printer print = new Printer();
        Custom odd = new Custom(false, n, print);
        Custom even = new Custom(true, n, print);
        odd.start();
        even.start();
    }
    
    public static void main(String[] args)
    {
        util(15);
    }
}
