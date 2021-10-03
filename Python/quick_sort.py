# QUICK SORT
n = int(input("Enter the number of list items: "))
arr = []
for i in range(0, n): 
    ele = int(input("Enter list item: ")) 
    arr.append(ele)

print("Initial array is:", arr)

def QuickSort(arr):
    
    elements = len(arr)
    
    #Base case
    if elements < 2:
        return arr
    
    current_position = 0 #Position of the partitioning element

    for i in range(1, elements): #Partitioning loop
         if arr[i] <= arr[0]:
              current_position += 1
              temp = arr[i]
              arr[i] = arr[current_position]
              arr[current_position] = temp

    temp = arr[0]
    arr[0] = arr[current_position] 
    arr[current_position] = temp #Brings pivot to it's appropriate position
    
    left = QuickSort(arr[0:current_position]) #Sorts the elements to the left of pivot
    right = QuickSort(arr[current_position+1:elements]) #sorts the elements to the right of pivot

    arr = left + [arr[current_position]] + right #Merging everything together
    
    return arr

print("Quick-sorted array is:",QuickSort(arr))

# Code contributed by Srinija Dharani
