#include<stdio.h>

int main()
{
    int l , b , h ;
    int v ;
    printf("Enter the l x b x h : \n");
    scanf("%d \n %d \n %d", &l ,&b ,&h);
    /*printf("Enter the b:");
    scanf("%d", &b);
    printf("Enter the h:");
    scanf("%d", &h);*/

    v = l * b * h ;
    
    printf(&v);
     
    return 0;
}