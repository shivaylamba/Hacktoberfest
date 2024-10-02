/*
Count Pairs in an Array
Given an array arr of n integers, count all pairs (arr[i], arr[j]) in it such that i*arr[i] > j*arr[j] and 0 ≤ i < j < n.

Note: 0-based Indexing is followed.

Example 1:

Input :
n = 4
arr[] = {8, 4, 2, 1}
Output :
2
Explanation:
If we see the array after operations
[0*8, 1*4, 2*2, 3*1] => [0, 4, 4, 3]
Pairs which hold the condition i*arr[i] > j*arr[j] are (4,1) and (2,1), so in total 2 pairs are available.
Example 2:

Input :
n = 7
arr[] = {5, 0, 10, 2, 4, 1, 6}
Output:
5
Explanation :
Pairs which hold the condition i*arr[i] > j*arr[j] are (10,2), (10,4), (10,1), (2,1) and (4,1), so in total 5 pairs are there.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function countPairs() which takes the array arr[] and its size n as inputs and returns the required result.

Expected Time Complexity: O(n*log(n))
Expected Auxiliary Space: O(n*log(n))

Constraints:
1 ≤ n ≤ 104
0 ≤ arr[i] ≤ 104
*/

class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here   
        int count = 0 ;
        for(int i = 0  ; i< n ; i++){
            arr[i] *=i;
        }
        for(int i = 0 ; i< n-1;i++){
            for(int j = i+1;j<n;j++){
                if(i<j && arr[i] > arr[j]){
                    count++;
                }
            }
        }
        return count ;
    }
};
