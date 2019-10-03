# mearging two sorted linked list

# node class - the structure of linked list
class Node:
	def __init__(self):
		self.value = None
		self.next = None

# function for printing linked list
def printList(root):
	while root != None:
		print(root.value, end = ' ')
		root = root.next
	print('')


# function for merging sorted linked list
def merge(L1, L2):

  # create new linked list pointer
  L3 = Node()
  prev = L3

  # while both linked lists are not empty
  while L1 != None and L2 != None:
    if L1.value <= L2.value:
      prev.next = L1
      L1 = L1.next
    else:
      prev.next = L2
      L2 = L2.next
    prev = prev.next

  # once we reach end of a linked list, append the other
  # list because we know it is already sorted
  if L1 == None:
  	prev.next = L2
  elif L2 == None:
  	prev.next = L1

  return L3.next



# first linked list
root1 = Node()
n1 = Node()
n2 = Node()

root1.value = 1
root1.next = n1

n1.value = 3
n1.next = n2

n2.value = 10

# second linked list
root2 = Node()
l1 = Node()
l2 = Node()
l3 = Node()

root2.value = 7
root2.next = l1

l1.value = 13
l1.next = l2

l2.value = 18
l2.next = l3

l3.value = 122


root = merge(root1, root2)
printList(root)
