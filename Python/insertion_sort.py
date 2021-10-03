# INSERTION SORT
n = int(input("Enter the number of list items: "))
arr = []
for i in range(0, n): 
    ele = int(input("Enter list item: ")) 
    arr.append(ele)

print("Initial array is:", arr)

def insertion(arr):
    index = range(1, len(arr))
    for i in index:
        sort = arr[i]
        
        while arr[i-1] > sort and i > 0:
            arr[i], arr[i-1] = arr[i-1], arr[i]
            i -= 1
    
    return arr

print("Insertion-sorted array is:", insertion(arr))

# Code contributed by Srinija Dharani
