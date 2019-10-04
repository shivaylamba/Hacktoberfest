class node:
    def __init__(self,val):
        self.val = val
        self.next = None

class list:
    def __init__(self):
        self.head=None
    def add(self,val):
        temp=node(val)
        temp.next=self.head
        self.head=temp
    def display(self):
        temp=self.head
        while temp:
            print(temp.val,end=' ')
            temp=temp.next
        print()
    def reverseList(self):
        left=self.head
        if left:
            right=left.next
            if right:
                left.next=None
                while right:
                    temp=right.next
                    right.next=left
                    left=right
                    right=temp
                self.head=left

l1=list()
print('Enter the number of nodes: ',end=' ')
num=int(input())
for i in range(num):
    l1.add(i)
print('List:')
l1.display()
l1.reverseList()
print('Reversed List:')
l1.display()
