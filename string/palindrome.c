#include<stdio.h>
main()
{
    int i,l,count=0,j;
    char c[20],d[20];
    printf("Enter the string:\n");
    gets(c);
    for(i=0;c[i]!=0;i++);
    printf("%d",i);
    for(j=0;j<i;j++)
    {
    for(l=i-1;l>=0;l--)
      {
        if(c[l]==c[j])
            count++;
        else
            break;
      }
    }
    if(count>0)
        printf("The string is a palindrome string.\n");
    else
        printf("The string is not a palindrome string.\n");
}
