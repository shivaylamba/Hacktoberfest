
a = int(input("Enter Triangle Side:- "))
b = int(input("Enter Triangle Side:- "))
c = int(input("Enter Triangle Side:- "))

if a==b==c:
    print("Equilateral Triangle")
elif a!=b and b!=c and c!=a:
    print("Scalene Triangle")
else:
    print("Isosceles Triangle")