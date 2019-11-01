# A simple python program to check if the number provided by the user is an Armstrong number or not


# Take input from the user
num = int(input("Enter the number to check: "))
sum = 0
# Find the sum of the cube of each digit
temp = num
while temp > 0:
   digit = temp % 10
   sum += digit ** 3
   temp //= 10
# display the result
if num == sum:
   print(num,"is an Armstrong number.")
else:
   print(num,"is not an Armstrong number.")
