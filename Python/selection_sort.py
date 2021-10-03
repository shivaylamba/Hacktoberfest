# SELECTION SORT
n = int(input("Enter the number of list items: "))
arr = []
for i in range(0, n): 
    ele = int(input("Enter list item: ")) 
    arr.append(ele)

print("Initial array is:", arr)

def selection(arr):
    for i in range(len(arr)):
        min_index = i
        for j in range(i+1, len(arr)):
            if arr[min_index] > arr[j]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

print("Insertion-sorted array is:", selection(arr))

# Code contributed by Srinija Dharani
