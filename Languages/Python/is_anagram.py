from collections import Counter 
def is_anagram(str1, str2): 
     return Counter(str1) == Counter(str2) 

str1 = input()
str2 = input()
print(is_anagram(str1, str2)) 
