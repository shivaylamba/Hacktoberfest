#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0)
            sum += i;
    }

    printf("Sum of even numbers till %d = %d\n", n, sum);
    return 0;
}
