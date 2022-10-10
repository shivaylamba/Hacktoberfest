#include<stdio.h>
main()
{
    int i,count=0;
    char c[20],ch;
    printf("Enter the string:\n");
    gets(c);
    printf("Enter the character to check its occurrence:\n");
    scanf("%c",&ch);
    for(i=0;c[i]!=0;i++)
    {
        if(c[i]==ch)
            count++;
    }
    printf("The number of times %c is repeated in %s is %d.\n",ch,c,count);
}
