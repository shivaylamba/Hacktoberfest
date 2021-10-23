#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

int main()
{

    int n,i,j,k,s,m,b,x=0,y,h;
    printf("EnTer tHe nUmBer YoU WaNt tO dIsplaY PattErn")
    scanf("%d", &n);
    k=1;
  	// Complete the code to print the pattern.
    for(i=n;i>0;i--)
    {
         s=n;
         b=n;
        for(j=0;j<i;j++)
        {
            printf("%d ",i);
        }

        for(j=2;j<i;j++)
        {
            if(i==1)
            {
                printf("2");
            }
            else
            printf("%d ",i);
        }
        b=b-x;
        for(m=0;m<k;m++)
        {
            if(b==1)
            {
                b=b+1;
            }
            else
            {
            printf("%d ",b);
            b++;
            }
        }



        printf("\n");



        for(m=0;m<k&&k<n;m++)
        {
            printf("%d ",s);
            s--;
        }
        k++;
        x++;
    }
    //END OF FIRST HALF
    y=n;
    for(i=1;i<n;i++)
    {
        h=n;
        b=n;
        for(j=y-2;j>0;j--)
        {
            printf("%d ",h);
            h--;
        }
        for(j=0;j<=i;j++)
        {
            printf("%d ",i+1);
        }
        y--;

        for(m=0;m<i;m++)
        {
            printf("%d ",i+1);
        }

        b=i+2;
         for(m=1;m<n-1&&b<=n;m++)
        {
           printf("%d ",b);
            b++;
        }

        printf("\n");
    }
     getch();
    return 0;
}

