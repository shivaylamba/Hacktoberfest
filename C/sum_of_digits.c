#include <stdio.h>

int reverse(int x);
int main()
{
    int x;
    printf("Enter a number to reverse: ");
    scanf("%d", &x); 
    printf("Reversed NUmber: %d", reverse(x));
}

int reverse(int x)
{
    int result = 0;
    while(x > 0)
    {    
        int j = x % 10;
        x /= 10;
        result += j;

    } 
    return result;
}