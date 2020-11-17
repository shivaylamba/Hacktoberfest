#include<stdio.h>
main()
{
    char c[20];
    printf("Enter the string:\n");
    gets(c);
    printf("The string in lower case is: %s\n",strlwr(c));
}
