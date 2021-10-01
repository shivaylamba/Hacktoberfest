/******* Binary Search in a rotated sorted array ******/
// Time complexity - O(logn)
// Space complexity - O(1)

/** Contributed by - Raunak Gayen **/


#include<iostream>
using namespace std;

int main()
{
    int arr[] = {5,6,7,8,9,10,1,2,3}; // here we have a rotated sorted array
    int n = sizeof(arr)/sizeof(arr[0]); // size in this case is going to be 9

    int target;
    cin>>target; // we ask the user to give a number as target

    int index = -1; // index is a variable that will be used to store the index of target if present

    int left = 0; // this is the left pointer initially pointing to the 0th index [first element]
    int right = n - 1; // this is the right pointer initially pointing to the (n-1)th index [last element]
    while(left <= right) // this loop continues until we find the target or left crosses right 
    {
        int mid = left + (right - left)/2; // we here calculate the middle index and compare everytime
        if(arr[mid] == target) // if our target is equal to arr[mid]
        {
            index = mid;
            break; // if arr[mid] equals target we break out of the while loop to print the index
        }
        else if(arr[mid] >= arr[0]) // here we check if the left part of the mid is sorted or not
        {
            if(target >= arr[0] && target <= arr[mid])  // now we check if target lies in the left zone bw mid and left
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1; // else target lies in the right zone bw mid and right
            }
        }
        else // this means right part is sorted
        {
            if(target >= arr[mid] && target <= arr[n-1]) // if target lies in the right zone
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1; //else it lies in the left zone
            }
        }
    }
    

    if(index == -1)
    {
        cout<<"Target not found in the array";
    }
    else
        cout<<"Target found at index -- "<<index;
    return 0;
}