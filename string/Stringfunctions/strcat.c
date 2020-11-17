#include<stdio.h>
main()
{
    int i;
    char c[20],s[20];
    printf("Enter the string 1:\n");
    gets(c);
    printf("Enter the string 2:\n");
    gets(s);
    printf("The new combined string is %s.\n",strcat(c,s));
}

