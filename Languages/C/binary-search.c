//complexity of binary search is O(log(n))

#include<stdio.h>

int binarySearch(int a[],int low,int high,int key)
{   
    int mid;
    if(low<=high)
    {
        mid=low+(high-1)/2;
        //if element is present at middle
        if(key==a[mid])
            return mid;
        else if(key>a[mid])
            return binarySearch(a,mid+1,high,key);
        else
            return binarySearch(a,low,mid-1,key);
    }
     // We reach here when element is not  present in array 
    return -1;
}
int main(void) 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 5; 
    int result = binarySearch(arr, 0, n - 1, x); 
    if(result == -1)
        printf("Element is not present in array"); 
    else
        printf("Element is present at index %d",result); 
    return 0; 
} 