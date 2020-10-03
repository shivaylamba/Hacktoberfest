#include<stdio.h>
main()
{
    int i;
    char c[20];
    printf("Enter the string:\n");
    gets(c);
    for(i=0;c[i]!='\0';i++);
    printf("The length of the string is %d.\n",i);
}
