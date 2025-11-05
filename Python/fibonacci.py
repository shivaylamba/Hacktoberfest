# fibonacci.py

def fibonacci(n):
    sequence = []
    a, b = 0, 1
    for _ in range(n):
        sequence.append(a)
        a, b = b, a + b
    return sequence

if __name__ == "__main__":
    try:
        terms = int(input("Enter number of Fibonacci terms: "))
        if terms <= 0:
            print("Please enter a positive integer.")
        else:
            print("Fibonacci sequence:")
            print(fibonacci(terms))
    except ValueError:
        print("Invalid input! Please enter an integer.")
