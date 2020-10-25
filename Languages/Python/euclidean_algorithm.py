# algorithm to get the greatest common divisor between two integers
def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)
