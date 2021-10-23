#include<stdio.h>
int main()
{
    int i,j,k,n;
    printf("enter the order");
    scanf("%d",&n);
    int A[n][n],B[n][n],C[n][n];
    printf("enter matrix A \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
        printf("\n");
    }
    printf("enter matrix B \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&B[i][j]);
        }
        printf("\n");

    }
    printf("the product of the matrices is \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           C[i][j]=0;
           for(k=0;k<n;k++)
            {
                C[i][j]=C[i][j]+A[i][k]*B[k][j];
            }
         printf("%d  ",C[i][j]);
        }
        printf("\n");
    }
}
