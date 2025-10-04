"""
This program checks if a number is prime (beginner-friendly, no functions).
"""

try:
    num = int(input("Enter a number: "))

    if num > 1:
        for i in range(2, num):
            if num % i == 0:
                print(num, "is NOT a Prime number ")
                break
        else:
            # This else belongs to the for-loop, not the if
            print(num, "is a Prime number ")
    else:
        print(num, "is NOT a Prime number ")
except ValueError:
    print("Please enter a valid integer.")
