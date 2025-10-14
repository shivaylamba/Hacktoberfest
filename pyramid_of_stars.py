# Program to create a pyramid of stars.

rows = int(input("Enter the number of rows: "))

for i in range(1, rows + 1):
    # Print Spaces
    for spaces in range(1, rows - i + 1):
        print(end=' ')

    # Print Stars
    for stars in range(1, i + 1):
        print('*', end=' ')

    # To create a new line
    print()
