#include<stdio.h>
#include<string.h>
main()
{
    int i,l,count1=0,count2=0,count3=0;
    char c[20];
    printf("Enter the string:\n");
    gets(c);
    for(i=0;c[i]!='\0';i++);
    for(l=0;l<i;l++)
    {
          if(c[l]>='A'&&c[l]<='Z')
                count1++;
          if(c[l]>='a'&&c[l]<='z')
                count2++;
          if(c[l]>='0'&&c[l]<='9')
                count3++;
    }
    if((count1>0&&count3>0)||(count2>0&&count3>0))
       printf("The string is an ALPHANUMERIC string.\n");
    else
       printf("The string is NOT an ALPHANUMERIC string.\n");
}
