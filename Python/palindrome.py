class PalindromeChecker:
    def __init__(self,value):
        self.value = value

    def is_Palindrome():
        raise NotImplemented("Subclass must implement the method!")
    
class StringPalindrome(PalindromeChecker):
    def is_Palindrome(self):
        cleaned_value = ''.join(self.value.lower().split())
        if cleaned_value == cleaned_value[::-1]:
            return True
        
class IntegerPalindrome(PalindromeChecker):
    def is_Palindrome(self):
        if str(self.value) == str(self.value)[::-1]:
            return True
        
def checkPalindrome(Palindrome_checker):
    if Palindrome_checker.is_Palindrome():
        print("It is a palindrome!")

    else:
        print("Not a palindrome!")

strchk = StringPalindrome(input("Enter a word: "))
intchk = IntegerPalindrome(int(input("Enter a number: ")))

checkPalindrome(strchk)
checkPalindrome(intchk)
        