#Python program to search for an element in a linked list using recursion
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.last_node = None

    def append(self, data):
        if self.last_node is None:
            self.head = Node(data)
            self.last_node = self.head
        else:
            self.last_node.next = Node(data)
            self.last_node = self.last_node.next

    def display(self):
        current = self.head
        while current is not None:
            print(current.data, end=' ')
            current = current.next

    def find_index(self, key):
        return self.find_index_helper(key, 0, self.head)

    def find_index_helper(self, key, start, node):
        if node is None:
            return -1

        if node.data == key:
            return start
        else:
            return self.find_index_helper(key, start + 1, node.next)


a_llist = LinkedList()
for data in [3, 5, 0, 10, 7]:
    a_llist.append(data)
print('The linked list: ', end='')
a_llist.display()
print()

key = int(input('What data item would you like to search for? '))
index = a_llist.find_index(key)
if index == -1:
    print(str(key) + ' was not found.')
else:
    print(str(key) + ' is at index ' + str(index) + '.')