import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class fractional_knapsack
{
    public static void main(String[] args)
    {
        List<Shares> shares = new ArrayList<>();
        getInput(shares);
        findSP_per_P(shares);
        showSharesTable(shares);

        sortInAsc_wrt_SP_per_P(shares);
    }

    private static void sortInAsc_wrt_SP_per_P(List<Shares> shares)
    {
        int i,j,len = shares.size();
        Shares obj1,obj2 ,tmp_obj;
        for(i=0;i<len-1;i++)
        {
            for(j=0;j<len;j++)
            {
                if(obj1.SP_per_P > obj2.SP_per_P)
                {
                    tmp = obj1.SP_per_P;
                   
                }
            }
        }
    }

    private static void findSP_per_P(List<Shares> shares)
    {
        int i=0;
        Shares objShares;
        for(i=0;i<shares.size();i++)
        {
            objShares = shares.get(i);
            objShares.SP_per_P = objShares.SP/ objShares.P;
            shares.set(i,objShares);
        }
    }

    private static void showSharesTable(List<Shares> shares)
    {
        Shares objShare;
        System.out.println("Name\tSP\tP\tNo.of Shares\tSP/P\n");
        for(int i=0;i< shares.size();i++)
        {
            objShare = shares.get(i);
            System.out.println("\n"+objShare.name + "\t" + objShare.SP + "\t" +
                    objShare.P + "\t" + objShare.numOfShares + "\t" + objShare.SP_per_P);
        }
    }

    private static void getInput(List<Shares> shares)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter share name, selling price,profit,no.of.shares respectively :");
        int i=0;
        String name;
        while(true)
        {
            System.out.println("Share " + (i+1) + "->");
            name = scan.nextLine();
            if(name.compareToIgnoreCase(".")==0)
                break;
            shares.add(new Shares(name,scan.nextInt(),scan.nextInt(),scan.nextInt()));
            i++;
            scan.nextLine();
        }
    }
}

class Shares
{
    String name;
    int SP, P , numOfShares;
    int SP_per_P;

    public Shares(String name , int SP , int P , int numOfShares)
    {
        this.name = name;
        this.SP = SP;
        this.P = P;
        this.numOfShares = numOfShares;
    }
}
