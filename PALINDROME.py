a = input()
b = a.split()
for i in range(int(len(b)/2)):
  if b[i] != b[len(b)-i-1]:
    print("String is NOT Palindrome")
    break
else:
  print("String is  Palindrome")
