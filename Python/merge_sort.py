# MERGE SORT
n = int(input("Enter the number of list items: "))
arr = []
for i in range(0, n): 
    ele = int(input("Enter list item: ")) 
    arr.append(ele)

print("Initial array is:", arr)

def mergeSort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]
        mergeSort(left)
        mergeSort(right)

        i, j, k = 0, 0, 0
        
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
              arr[k] = left[i]
              i += 1
            else:
                arr[k] = right[j]
                j += 1
            # Move to the next slot
            k += 1

        # For all the remaining values
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            arr[k]=right[j]
            j += 1
            k += 1
mergeSort(arr)
print("Merge-sorted array is:", arr)

# Code contributed by Srinija Dharani
