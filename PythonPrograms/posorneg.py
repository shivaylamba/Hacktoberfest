def positiveornegative(num):
    if num > 0:
        print(f"{num} is positive")
    elif num < 0:
        print(f"{num} is negative")
    elif num == 0:
        print("You entered zero")

num = int(input("Enter a number: "))
positiveornegative(num)