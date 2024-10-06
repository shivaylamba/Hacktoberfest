#include <stdio.h>
int main() {
    // Loop from 1 to 100
    for (int i = 1; i <= 100; i++) {
        // Check if the number is divisible by both 3 and 5
        if (i % 3 == 0 && i % 5 == 0) {
            printf("FizzBuzz\n");
        }
        // Check if the number is divisible by 3
        else if (i % 3 == 0) {
            printf("Fizz\n");
        }
        // Check if the number is divisible by 5
        else if (i % 5 == 0) {
            printf("Buzz\n");
        }
        // If none of the above, print the number
        else {
            printf("%d\n", i);
        }
    }

    return 0;
}

