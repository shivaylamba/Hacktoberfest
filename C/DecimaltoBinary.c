#include <stdio.h>
#include <stdlib.h>

void dectobin(int n)
{
    if(n > 0)
    {
        dectobin(n/2);
        printf("%d",n%2);
    }
    return;
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    dectobin(n);
}
