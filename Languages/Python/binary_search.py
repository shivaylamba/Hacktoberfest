#Run a binary search on a sorted array
from random import sample, choice

def search(array, num, left, right):
	mid = (left + right) // 2
	if num == array[mid]:
		return mid
	elif num > array[mid]:
		if mid == left: return -1
		return search(array, num, mid, right)
	if mid == right: return -1
	return search(array, num, left, mid)

array = sorted(sample(range(100), 10))
value = choice(array)
print("Find index of %i in" % value, array)
print(search(array, value, 0, 10))
