#include<stdio.h>
main()
{
    int i,count=0;
    char ch[20];
    printf("Enter the string:\n");
    gets(ch);
    for(i=0;ch[i]!=0;i++)
    {
        if(ch[i]=='a'||ch[i]=='e'||ch[i]=='i'||ch[i]=='o'||ch[i]=='u')
            count++;
    }
    printf("The number of vowels in %s are %d.",ch,count);
}
