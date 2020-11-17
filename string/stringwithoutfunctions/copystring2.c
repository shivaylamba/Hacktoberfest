#include<stdio.h>
main()
{
    int i;
    char c[20],s[20];
    printf("Enter the string 1:\n");
    gets(c);
    for(i=0;c[i]!='\0';i++)
    {
        s[i]=c[i];
    }
    s[i]='\0';
    for(i=0;s[i]!='\0';i++)                                 //method1
    {
        printf("%c",s[i]);
    }
    printf("\n");
    printf("%s\n",s);                                       //method 2

    puts(s);                                                //method 3
}
