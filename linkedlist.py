# -*- coding: utf-8 -*-
"""
Created on Mon Jun 27 16:51:26 2022

@author: nimsh
"""

class Node:
    """
    An object for storing a single node of a linked list
    Models two attributes - data & the link to the next node in the list
    """
    
    data = None
    next_node = None
    
    def __init__(self, data):
        self.data = data
        
    def __repr__(self):
        return "<Node data: %s" % self.data


class LinkedList:
    
    """
    Singly LL
    """
    #head = None
    
    def __init__(self):
        self.head = None
        
    def is_empty(self):
        return self.head == None
    
    def size(self):
        """
        Returns the no of nodes in the list
        Takes O(n) time
        """
        current = self.head
        count = 0
        
        while current: # current != None
            count = count +1 
            current = current.next_node
            
        return count
            
    
    def add(self, data):
        """
        Adds new Node containing data 
        at the head of the list
        Take O(1) : constant time : 
                   best case scenario
        """
        new_node = Node(data)
        new_node.next_node = self.head
        self.head = new_node 
        
    def search(self, key):
        
        """
        search for the 1st node conatining data that matches the key
        returns the node or none if not found
        Take O(n) time
        """
        
        current = self.head
        
        while current:
            if current.data == key:
                return current
            else:
                current = current.next_node
        return None
    
    def insert(self, data, index):
        
        """
        INserts a new node conataining data at index posn
        insertion takes O(1) time
        but finding node at insertion point take O(n) time
        
        Overall o(n) time
        """
        
        if index == 0:
            self.add(data)
        if  index > 0:
            new = Node(data)
            
            position = index
            current = self.head
            while position > 1:
                current = node.next_node
                position -= 1
            prev_node = current
            next_node = current.next_node
            
            prev_node.next_node = new
            new_next_node = next
            
    def remove(self, key):
        
        """
        removes node conataining data that matches the key
        return node or none if key doesn't exist
        takes O(n) time
        """
        current = self.head()
        previous = None
        found = False
        
        while current and not found:
            if current.data == key and current is self.head:
                found = True
                self.head = current.next_node
            elif current.data == key:
                found = True
                previous.next_node = current.next_node
            else:
                previous = current
                current = current.next_node
                
            return current
        
    def node_at_index(self, index):
        if index == 0:
            return self.head
        else:
            current = self.head
            position = 0
            
            while position < index:
                current = current.next_node
                position += 1
                
            return current
        
            
        
    def __repr__(self):
        """
        Returns a string representation of the list
        Take O(n) time
        """
        
        nodes=[]
        current = self.head
        
        while current:
            if current is self.head:
                nodes.append("[Head: %s]" % current.data)
            elif current.next_node is None:
                nodes.append("[Tail : %s]" % current.data)
            else:
                nodes.append("[%s]" % current.data)
                
            current = current.next_node
        return '->'.join(nodes)
    
    
    