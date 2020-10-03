#include<stdio.h>
main()
{
    int i,flag=0,m,n;
    char c[20],s[20];
    printf("Enter string 1:\n");
    gets(c);
    printf("Enter string 2:\n");
    gets(s);
    m=strlen(c);
    n=strlen(s);
    if(m==n)
    {
          for(i=0;s[i]!='\0';i++)
          {
              if(s[i]==c[i])
              {
                flag=1;
              }
              else
               {
                break;
               }
          }
    }
    if(flag==0)
        printf("The strings are not equal.\n");
    else
        printf("The strings are equal.\n");
}
