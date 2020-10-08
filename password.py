letters = 'abcdefghijklmnopqrstuvwxyz'
def convert(string, step):
    converted = ""
    for char in string:
        if char != "z":
            converted += letters[letters.index(char) - step]
        else:
            converted += letters[step+1]
    return converted

x = input("enter the string: ")
steps= int(input("enter step"))
print(convert(x, steps))
