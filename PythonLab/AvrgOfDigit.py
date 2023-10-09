
    
sum = 0 
avrage = 0
a = input("Please Enter 5 Digit :- ")
n= len(a)

while (not a.isdigit()) or (n !=5) :
       a = input("Please Enter 5 Digit :- ")
       n = len(a)
a = int(a)
while a !=0 :
       digit = a%10
       sum += digit
       a = a//10
avrage = int(sum/n)
print("Avarage is :- ", avrage)
# if a.isd