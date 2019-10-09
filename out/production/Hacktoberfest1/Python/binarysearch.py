# Function for binary searching
def binarysearch(alist,x):
    beg=0
    end=len(alist)-1
    found=False
    while (beg<=end and not found):
        mid=(beg+end)//2
        if x==alist[mid]:
            flag=True
        if x<alist[mid]:
            end=mid-1
        if x>alist[mid]:
            beg=mid+1
        return found
# Inputting the list and the element to search

n=int(input("enter number of list elements: "))
l=[]
print("enter list elements: ")
for i in range(0,n):
    a=int(input())
    l.append(a)
y=int(input("enter the element to search: "))

#calling the binary search function 

if binarysearch(l,y) : print ("found")
else: print("not found")
