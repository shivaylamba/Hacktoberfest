s = input("Enter phone number in format '000-000-0000': ")
if(s[0:3].isdigit() and s[4:7].isdigit() and s[8:12].isdigit()):
    if(s[3] == '-' and s[7] == '-'):
        print("number is valid")
    else:
        print("Not Valid: Missing '-'")
else:
    print("Not Valid")


