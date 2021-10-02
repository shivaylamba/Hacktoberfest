#include<stdio.h>
void main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    if(n>=0)
    {
        if(n&1)
        printf("Odd");
        else
        printf("Even");
    }
    
}