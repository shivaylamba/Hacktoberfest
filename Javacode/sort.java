import java.io.*;
import java.util.*;

class insert{
   void sort(int A[])
    {
        int i,j,v,n=A.length;
        for(i=1;i<n;++i)
        {
            v=A[i];
            j=i-1;
            while(j>=0&&A[j]>v)
            {
                A[j+1]=A[j];
                j--;
            }
            A[j+1]=v;
        }
    }   
    public static void main(String[] arg)
    {
        insert i=new insert();
        int A[] ={9,8,7,6,5,4,3,2,1};
        i.sort(A);
        for(int j=0;j<A.length;j++)
        {
            System.out.print(A[j]+ "  ");
        }
    }
}
