print("Hello Welcome to Calc by Karan Dhingra")

a = input("Enter the First Number for operation : ")
b = input("Enter the Second number for operation : ")

ch = input("Enter the operator (+, -, *, /, **, %) : ")

if ch == '+':
    print("Required Solution is : ",float(a) + float(b))
elif ch == '-':
    print("Required Solution is : ",float(a) - float(b))
elif ch == '*':
    print("Required Solution is : ",float(a) * float(b))
elif ch == '/':
    print("Required Solution is : ",float(a) / float(b))
elif ch == '%':
    print("Required Solution is : ",float(a) % float(b))
elif ch == '**':
    print("Required Solution is : ",float(a) ** float(b))

print("ThankYou For Using Karan's Calc")
