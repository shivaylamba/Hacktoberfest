#include<stdio.h>
main()
{
    char c[20];
    printf("Enter the string:\n");
    gets(c);
    printf("The string in upper case is: %s\n",strupr(c));
}

