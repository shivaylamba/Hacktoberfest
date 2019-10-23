def merge(arr, lb, mb, ub):
    n1 = mb - lb + 1
    n2 = ub- mb
    LeftSubArray = [0] * (n1)
    RightSubArray = [0] * (n2)
    for i in range(0 , n1):
        LeftSubArray[i] = arr[lb + i]
    for j in range(0 , n2):
        RightSubArray[j] = arr[mb + 1 + j]
    
    i, j, k = 0, 0, lb
    while i < n1 and j < n2:
        if LeftSubArray[i] <= RightSubArray[j]:
            arr[k] = LeftSubArray[i]
            i += 1
        else:
            arr[k] = RightSubArray[j]
            j += 1
        k += 1
        
    while i < n1:
        arr[k] = LeftSubArray[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = RightSubArray[j]
        j += 1
        k += 1
 
def mergeSort(arr, lb, ub): 
	if lb < ub:
		mb = (lb+(ub-1))/2

		mergeSort(arr, lb, mb) 
		mergeSort(arr, mb+1, ub) 
		merge(arr, lb, mb, ub) 


def main():
    arr = list()
    print("Enter the elements of array to be sorted.\
          Type 'x' (along with inverted commas) for termination")
    while True:
        el = input()
        if el is 'x' or el is 'X':
            break
        else:
            arr.append(int(el))

    print("Given Sequence is: {}".format(arr))
    ub = len(arr)
    mergeSort(arr, 0, ub - 1)
    print("Sorted Sequence is: {}".format(arr))

if __name__ == "__main__":
    main()
