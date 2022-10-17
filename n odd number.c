#include <stdio.h>

void main()
{
   int i,n;

   printf("Input number of terms : ");
   scanf("%d",&n);
   printf("\nThe Odd numbers are :");
   for(i=1;i<=n;i++)
   {
     printf("%d ",2*i - 1);
   }

} 
