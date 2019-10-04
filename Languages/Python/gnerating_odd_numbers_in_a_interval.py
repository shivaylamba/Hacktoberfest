# specifying the end parameters of an interval
start, end = 10, 29

# iterative construct to get each value lying in the interval
for num in range(start, end + 1): 

	# check whether the selected number is odd or not
	if num % 2 != 0: 
		print(num, end = " ")

  # otherwise skip   
	else:
		pass
