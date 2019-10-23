"""
This is Bubble sort Algorithm
"""

def bubbleSort(arr):
    size = len(arr)
    for i in range (0, size-1):
        for j in range (0, size - i - 1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    
    return arr

arr = [5, 3, 4, 1, 2, 6]
print("Sorted Array = {}".format(bubbleSort(arr)))
