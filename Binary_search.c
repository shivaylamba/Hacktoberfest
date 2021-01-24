#include<stdio.h> #include<conio.h>
int main()
{
   int i, a[10], n, num,mid,low,high;
   printf ("enter the number of terms");
   scanf ("%d", &n);
   printf ("enter the array");
   for(i=0;i<n;i++)
   {
      scanf ("%d", &a[i]);
   }
   printf ("enter the number to be searched"); 
   scanf ("%d", &num);
   low=0;
   high=n-1;
   mid=(low+high)/2;
   while(low<=high)
   {
       if(a[mid]<num)
       {
          low=(mid+1);
          mid=(low+high)/2;
      }
      else;
      {
         if(a[mid]==num)
         {
            printf("number is found");
            break;
         }
         else;
         {
             high=mid-1; 
             mid=(high+low)/2;
         }
         if(low>high)
         {
           printf("number is not found");
         }
       }  
       
   }
}
