lookup_table = {'A' : 'Z', 'B' : 'Y', 'C' : 'X', 'D' : 'W', 'E' : 'V', 
		'F' : 'U', 'G' : 'T', 'H' : 'S', 'I' : 'R', 'J' : 'Q', 
		'K' : 'P', 'L' : 'O', 'M' : 'N', 'N' : 'M', 'O' : 'L', 
		'P' : 'K', 'Q' : 'J', 'R' : 'I', 'S' : 'H', 'T' : 'G', 
		'U' : 'F', 'V' : 'E', 'W' : 'D', 'X' : 'C', 'Y' : 'B', 'Z' : 'A'} 

def atbash(message): 
	cipher = '' 
	for letter in message: 
		if(letter != ' '): 
			cipher += lookup_table[letter] 
		else: 
			cipher += ' '

	return cipher 
def main(): 
	message = input()
	print(atbash(message.upper())) 
if __name__ == '__main__': 
	main() 
