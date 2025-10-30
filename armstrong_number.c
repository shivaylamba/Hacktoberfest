#include <stdio.h>
#include <math.h>

int main() {
    int n, temp, digits = 0, sum = 0, rem;
    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = n;
    while (temp != 0) {
        rem = temp % 10;
        sum += pow(rem, digits);
        temp /= 10;
    }

    if (sum == n)
        printf("%d is an Armstrong number.\n", n);
    else
        printf("%d is not an Armstrong number.\n", n);

    return 0;
}
