#include <stdio.h>
#include <stdlib.h>
void main()
{
 char a[11][100];
 int i,s=0,m;
for(i=0;i<=10;i++)
 {
 gets(a[i]);
 }
for(i=0;i<=10;i++)
 { 
  m=length(a[i]);
 if(a[i][m-2]=='k'&&a[i][m-1]=='a'&&a[i][m]=='r')
  {
     s=s+1;
  }
 printf("The number of cricketers' name ending with 'kar' are : %d",s);
}
}

