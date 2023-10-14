
sum =0
a = input("Enter a 10 digit :- ")
n= len(a)
while (not a.isdigit()) or (n !=10) :
       a = input("Please Enter 10 Digit :- ")
       n = len(a)

a = int(a)

while a !=0 :
       digit = a%100
       print(digit, end= " ")
       sum = sum + digit
       a = a//100
avrage = int(sum/5)
print("\nThe sum is:- ", sum,  "\n Avarage is :- ", avrage)