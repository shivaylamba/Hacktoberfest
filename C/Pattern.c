#include<stdio.h>
#include<conio.h>

void main() {
    int i,j;

    for(i=1;i<=4;i++)      //rows
    {
        for(j=4;j>=i;j--)    //column 
        {
            printf("* ");
            // if(j>=5-i)
            //     printf("* ");
            // else
            //     printf(" ");
        
        }
        printf("\n");
    }

}
