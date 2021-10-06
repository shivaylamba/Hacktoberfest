#Calculator

number1 = int(input('Enter Number 1: '))
number2 = int(input('Enter Number 2: '))

operator = input('Enter operator out of the following:\n +\t-\t*\t/\t**\t')

valid_operators = ['+', '-', '*', '/', '**']

while True:
    if operator not in valid_operators:
        print('Invalid operator')
        operator = input('Enter operator out of the following:\n +\t-\t*\t/\t**\t')
    if operator in valid_operators:
        break

if operator == valid_operators[0]:
    print('Result of addition of the numbers is:', number1+number2)
elif operator == valid_operators[1]:
    result = abs(number2-number1)
    print('Result of subtraction of the numbers is:', result)
elif operator == valid_operators[2]:
    print('Result of multiplication of the numbers is:', number1*number2)
elif operator == valid_operators[3]:
    if number2 == 0:
        print('Cant be divided by zero.')
    else:
        print('Result of division of the numbers is:', number1/number2)
elif operator == valid_operators[4]:
    print('Result of exponentiation of the numbers is:', number1**number2)

