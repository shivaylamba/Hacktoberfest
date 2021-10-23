import java.util.*;

public class stable{

int [][] men= new int[50][50];
int [][] women= new int[50][50];
int [] mMark=new int[50];
int [] wc=new int[50];
int [] mc=new int[50];
Scanner o=new Scanner(System.in);
public void womenpref(int n)
{
	System.out.println(" enter the women preferne list");
	for(int i=1;i<=n;i++)
	{
	  System.out.println("enter the prefreence of"+i+"women");
	    for(int j=1;j<=n;j++)
		{
		   System.out.println("enter the"+j+" prefreence of"+i+"women");
			women[i][j]=o.nextInt();
		}
	}
}
public void printwomen(int n)
{
	System.out.println("women prefference list");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			System.out.print("\t"+women[i][j]);
		}
		System.out.println("\n");
	}
}
public void menpref(int n)
{
        System.out.println(" enter the men preferne list");
        for(int i=1;i<=n;i++)
        {
          System.out.println("enter the prefreence of"+i+"men");
            for(int j=1;j<=n;j++)
                {
                   System.out.println("enter the"+j+" prefreence of"+i+"men");
                        men[i][j]=o.nextInt();
                }
        }
}       
public void printmen(int n)
{       
        System.out.println("men prefference list");   
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=n;j++)
                {
                        System.out.print("\t"+men[i][j]);
                }
		System.out.println("\n");
        }
}
public boolean wPrefersMOverM1(int w,int m,int m1,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(women[w][i]==m)	 
			return true;		
		else if(women[w][i]==m1)
			return false;
	}
	return false;
}
public void stable(int n)
{
	int i,fc;
	for(i=1;i<=n;i++)
	{
		mMark[i]=0;
		wc[i]=-1;
	}
	fc=n;
	while(fc>0)
	{
		int m;
		for(m=1;m<=n;m++)
			if(mMark[m]==0)
			break;
		for(i=1;i<=n&& mMark[m]==0;i++)
		{
			int w=men[m][i];
			if(wc[w]==-1)	
			{ 
				wc[w]=m;	
				mMark[m]=1;	
				fc--; 
			}
			else
			{
				int m1=wc[w];
				if(wPrefersMOverM1(w,m,m1,n))	
				{
					wc[w]=m;								      mMark[m]=1;		
					mMark[m1]=0;
				} 	
			}
		}
	}
}
public void afterstable(int n)
{
	
	for(int i=1;i<=n;i++)
	{
		mc[wc[i]]=i;
	}

	for(int i=1;i<=n;i++)
		System.out.println(" "+i+" is paired with"+mc[i]);

}
}
