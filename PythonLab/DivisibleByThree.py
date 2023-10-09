sum =0
a = input("Enter a Number :- ")
n= len(a)
while (not a.isdigit()) :
       a = input("Please Enter  Number :- ")
       n = len(a)

a = int(a)
while a != 0 :
    if n %2==0 :
        digit = a%100
        print(digit, end= " ")
        sum = sum + digit
        a = a//100
        t = int(sum//2)  

    elif n %3==0 :
        digit = a%10**3
        print(digit, end= " ")
        sum = sum + digit
        a = a//10**3
        t = int(sum//3) 

    elif n %5==0 :
        digit = a%10**5
        print(digit, end= " ")
        sum = sum + digit
        a = a//10**5
        t = int(sum//5) 

    elif n %7==0 :
        digit = a%10**7
        print(digit, end= " ")
        sum = sum + digit
        a = a//10**7
        t = int(sum//7) 

avarage = int(sum/t)
print("\nThe length is:- ", n,  "\n Sum is :- ", sum, "\n Avarage is :-", avarage)
