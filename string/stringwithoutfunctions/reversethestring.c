#include<stdio.h>
main()
{
    int i,l,s;
    char c[20];
    printf("Enter the string:\n");
    gets(c);
    for(i=0;c[i]!='\0';i++);
    for(l=0;l<i/2;l++)
    {
        s=c[l];
        c[l]=c[i-l-1];
        c[i-l-1]=s;
    }
    printf("Reverse of string is %s.",c);
}

