# convertor tempreture :-

temp = input(" Input the tempreture you like convert :- ")

if temp[-1] == "F" or "f":
    # delete last str item to characters and remove its.
    f = "".join(filter(str.isdecimal, temp))
    f=int(f)
    f = (f * 9/5) + 32
    print("Temp in Celsius :- ",f)
elif temp[-1] == "C" or "c":
    c = "".join(filter(str.isdecimal, temp))
    c=int(c)
    c = (c - 32) * 5/9
    print("Temp in Forenhite :- ",c)
else:
    print("Invalid Input")

