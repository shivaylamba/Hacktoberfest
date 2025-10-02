#include <stdio.h>

int main() {
    int num, reversed;

    // Ask user for a 3-digit number
    printf("Enter a 3-digit number: ");
    scanf("%d", &num);

    // Check if number is actually 3-digit
    if(num < 100 || num > 999) {
        printf("Please enter a valid 3-digit number.\n");
        return 1;
    }

    // Reverse the number
    reversed = (num % 10) * 100 + ((num / 10) % 10) * 10 + (num / 100);

    // Print the reversed number
    printf("Reversed number: %d\n", reversed);

    return 0;
}
