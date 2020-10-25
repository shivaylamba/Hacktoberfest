# function to check if a string is 
# palindrome or not 
def isPalindrome(string): 
	# Simply using the python functionality
	return string == string[::-1]

# driver program
s = "malayalam"
ans = isPalindrome(s) 

if (ans): 
	print("Yes") 
else: 
	print("No") 
