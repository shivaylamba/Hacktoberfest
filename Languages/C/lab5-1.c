#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
 char a[11][100];
 int i,s=0,m;
printf("Enter names of 11 players : \n");
for(i=0;i<=10;i++)
 {
 scanf("%c \n",a[i][100]);
 }
for(i=0;i<=10;i++)
 { 
  m=strlen(a[i]);
 if(a[i][m-2]=='k'&&a[i][m-1]=='a'&&a[i][m]=='r')
  {
     s=s+1;
  }
 }
 printf("The number of cricketers' name ending with 'kar' are : %d",s);

}

