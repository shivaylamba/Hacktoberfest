#include<stdio.h>
main()
{
    char c[20];
    printf("Enter the string:\n");
    gets(c);
    printf("The reverse is %s.",strrev(c));
}
