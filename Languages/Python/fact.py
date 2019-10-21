def fact(n):
	if n==1:
		return 1

	else:
		return n*fact(n-1)

t = int(input())
while t!=0:
	n = int(input())
	f = fact(n)
	print(f)
	t=t-1
