#Binary search of First and Last occurence

'''
Ques: AMAZON
First and last occurrences of X 
Basic Accuracy: 47.1% Submissions: 13501 Points: 1
Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Note: If the number x is not found in the array just print '-1'.

Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case contains two integers n and x. The second line contains n spaced integers.

Output:
Print index of the first and last occurrences of the number x with a space in between.

Constraints: 
1<=T<=100
1<=n,a[i]<=1000

Example:
Input:
2
9 5
1 3 5 5 5 5 67 123 125
9 7
1 3 5 5 5 5 7 123 125

Output:
2 5
6 6
'''

#code
def BinarysearchLast(arr,no,n):
    
    left = 0
    right = n-1
    result=-1

    while(left<=right):
        mid = (left+right)//2

        if arr[mid]==no:
            result=mid
            left=mid+1

        elif arr[mid]>no:
            right=mid-1
        
        else:
            left=mid+1

    return result
    
def BinarysearchFirst(arr,no,n):
    
    left = 0
    right = n-1
    result=-1

    while(left<=right):
        mid = (left+right)//2

        if arr[mid]==no:
            result=mid
            right=mid-1

        elif arr[mid]>no:
            right=mid-1
        
        else:
            left=mid+1

    return result  
   

t=int(input())

for _ in range(t):

    n,no =[int(x) for x in input().split()]
    
    arr=[int(x) for x in input().split()]
    
    indexFirst=BinarysearchFirst(arr,no,n)
    indexLast=BinarysearchLast(arr,no,n)
    if indexFirst==-1:
        print(-1)
    else:print(indexFirst,indexLast)    

