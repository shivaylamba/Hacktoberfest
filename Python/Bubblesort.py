def bubbleSort(arr, n) :
    for i in range(len(arr)):

        for j in range(len(arr)-i-1):
            if arr[j] > arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
    return arr

#to print the array/list
def printList(arr, n) : 
    for i in range(n) :
        print(arr[i], end = " ")
    print()


#main
n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))

bubbleSort(arr, n)
printList(arr, n)
