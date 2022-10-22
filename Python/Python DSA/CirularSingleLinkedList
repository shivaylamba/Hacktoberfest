# circular single linked list







from operator import ne
from pipes import Template
from platform import node


class Node:
    def __init__(self,value=None) :
        self.value=value
        self.next=None


class CirSingleList:
    def __init__(self):
        self.head=None
        self.tail=None
    
    def __iter__(self):
        node=self.head
        while node:
            yield node
            if node.next==self.head:
                break
            node=node.next

        
    def CreateList(self,nodeval):
        node=Node(nodeval)
        node.next=node
        self.head=node
        self.tail=node
        # return "the clls has been created"

    
    def insert(self,value,location):
        node=Node(value)

        if self.head is None:
            # return "nah"
            self.tail=node
            self.head=node
        if location==0: 
            node.next=self.head
            self.head=node
            self.tail.next=node

        elif location==-1:
           
            self.tail.next=node
            self.tail=node
            
            

        else:
            tempnode=self.head
            index=0
            while index< location-1:
                index+=1
                tempnode=tempnode.next
            
            nextnode=tempnode.next
            node.next=nextnode
            tempnode.next=node
           
    def transverse(self):
        Tempnode=self.head
        while Tempnode:
            print(Tempnode.value)
            Tempnode=Tempnode.next
            if Tempnode==self.tail.next:
                break

    def search(self,value):
        Tempnode=self.head
        while Tempnode:
            if Tempnode.value == value:
                print("found")
            Tempnode=Tempnode.next
            if Tempnode==self.tail.next:
                break

    
    def delete(self,location):
        if self.head is None:
            return"does not exist"
        
        else:
            if location ==0:
                if self.head==self.tail:
                    self.head.next=None
                    self.head=None
                    self.tail=None
                 
                
                else:
                    self.head=self.head.next
                    # it actually means next node's next pointer
                    self.tail.next=self.head
            
            elif location ==-1:
                if self.head==self.tail:
                    self.head.next=None
                    self.head=None
                    self.tail=None
                
                else:
                    node=self.head
                    while node is not None:
                        if node.next==self.tail:
                            break
                        node=node.next
                    
                    node.next=self.head
                    self.tail=node

            else:
                tempnode=self.head
                index=0
                while index<location-1:
                    tempnode=tempnode.next
                    index+=1
                
                nextnode=tempnode.next
                tempnode.next=nextnode.next
              
    def deleteall(self):
        self.tail.next=None
        self.head=None
        self.tail=None
    


                


            




CircularLinkedList=CirSingleList()
# CircularLinkedList.CreateList(1)

CircularLinkedList.insert(1,0)

CircularLinkedList.insert(2,-1)

CircularLinkedList.insert(3,-1)

CircularLinkedList.insert(4,-1)
# CircularLinkedList.insert(1,-2)
# CircularLinkedList.insert(2,-3)
# CircularLinkedList.insert(3,-4)

CircularLinkedList.transverse()
CircularLinkedList.search(1)
CircularLinkedList.delete(3)
CircularLinkedList.deleteall()

print([i.value for i in CircularLinkedList])



