#include<stdio.h>
main()
{
    int i;
    char c[20],s[20];
    printf("Enter the string 1:\n");
    gets(c);
    printf("Enter the string 2:\n");
    gets(s);
    i=strcmp(s,c);
    if(i==0)
        printf("The strings are same.\n");
    else
        printf("The strings are different.\n");
}
