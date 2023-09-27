#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number to reverse: ");
    scanf("%d", &num);

    int temp = num;
    while(temp > 0)
    {    
        int j = temp % 10;
        temp /= 10;
        printf("%d", j);

    }   
}