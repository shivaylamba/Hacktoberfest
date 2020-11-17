import math


def wilsonTheorem():
    """
    Check if number is prime. This function check the Wilson's Theorem --> (p - 1)! + 1 divisible p.
    """
    try:

        number = int(input("Enter a integer number: "))
        result = (math.factorial(number - 1) + 1) % number == 0
        if result:
            print(f"The number {number} is prime.")
        else:
            print(f"The number {number} is not prime.")
    except:
        print(f"The number must be an integer.")


if __name__ == '__main__':
    wilsonTheorem()
    