a = input("Enter numbers in space") #input in form of string
a_list = a.split() #string method to convert spaced string in list members
sum=0
for i in a_list:
	sum = sum + int(i)
print(a_list)
print(sum)

avg = sum/len(a_list) #avg = sum/no. of terms (calculated by using length of list)
print(avg)
