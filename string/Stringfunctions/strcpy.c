#include<stdio.h>
main()
{
    char c[20],s[20];
    printf("Enter the string:\n");
    gets(c);
    printf("The string is %s.",strcpy(s,c));
}
