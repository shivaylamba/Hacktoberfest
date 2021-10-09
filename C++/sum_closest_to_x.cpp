// https://www.geeksforgeeks.org/given-sorted-array-number-x-find-pair-array-whose-sum-closest-x/

#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int arr[] = {1, 3, 4, 7, 10}, x = 15;
    int size = (sizeof(arr)/ sizeof(int));
    int *start=&arr[0], *end=&arr[size-1];

    int diff=INT_MAX, final_sum=0, sum=0;
    while(start < end)
    {
        sum = *start + *end;
        if(abs(sum-x) < diff)
        {
            diff = abs(sum-x);
            final_sum = sum;
        }

        if(sum > x)
            end--;
        else 
            start++;
    }
    cout<<final_sum;
}