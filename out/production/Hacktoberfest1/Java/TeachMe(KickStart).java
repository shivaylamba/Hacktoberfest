import java.util.*;
class Solution
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int i=0;i<t;i++)
        {
            int count=0;
            int n=sc.nextInt();
            int s=sc.nextInt();
            int a[][]=new int[n][s+1];
            for(int j=0;j<n;j++)
            {
                for(int m=0;m<s+1;m++)
                a[j][m]=0;
            }
            for(int j=0;j<n;j++)
            {
                int k=sc.nextInt();
                for(int m=0;m<k;m++)
                {
                    int q=sc.nextInt();
                    a[j][q]=1;
                }
            }
            for(int r=0;r<n;r++)
            {
                int crow=r;
                for(int ro=0;ro<n;ro++)
                {
                    if(ro==crow)
                    continue;
                    for(int col=0;col<s+1;col++)
                    {
                        if(a[crow][col]!=a[ro][col]&& a[crow][col]!=0)
                        {
                            count++;
                            break;
                        }
                    }
                }
            }
            System.out.println ("Case #"+(i+1)+": "+ count);
        }
    }
}
