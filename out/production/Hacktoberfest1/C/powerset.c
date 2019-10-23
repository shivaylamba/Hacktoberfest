#include<stdio.h>
#include<math.h> 
int main()
{
int a[10],i,j,s,n;
printf("Enter the size of set\n");
scanf("%d",&n);
printf("Enter elements of set\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
s=pow(2,n);
for(i=0;i<s;i++)
{
printf("(");
for(j=0;j<n;j++)
{
if(i&(1<<j))
printf("%d ",a[j]);
}
printf(")\n");
}
return 0;
}
