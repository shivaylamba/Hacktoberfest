from random import randint
a=randint(1,200)
print('computer_guess',a)
pg=int(input('enter your guess'))
#print(pg)
diff=abs(pg-a)
if(diff<=10 and diff>=1):
	print('fan')
else:
	print('fake')