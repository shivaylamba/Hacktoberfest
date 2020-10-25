# Function to print even numbers
def printEvenNumbers(arr):
	for each in arr:
		if each % 2 == 0:
			print(each)


# Array input from the user
arr = [int(x) for x in input().split()]

# Call the function and pass arr as the argument
printEvenNumbers(arr)