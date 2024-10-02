/*
Triplet Sum in Array
Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.
Example 1:Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13.
Example 2:
Input:
n = 5, X = 10
arr[] = [1 2 4 3 6]
Output:
1
Explanation:
The triplet {1, 3, 6} in 
the array sums up to 10.
Your Task:
You don't need to read input or print anything. Your task is to complete the function find3Numbers() which takes the array arr[], the size of the array (n) and the sum (X) as inputs and returns True if there exists a triplet in the array arr[] which sums up to X and False otherwise.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ n ≤ 103
1 ≤ A[i] ≤ 105
*/
/*
    MOST OPTIMZIED APPROACH
Expected Time Complexity: O(n^2)
Expected Auxiliary Space: O(1)
*/
class Solution {
  public:
    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int arr[], int n, int x) {
        // Your Code Here
        if(n<3) return 0;
        sort(arr,arr+n);
        for(int i  =0  ; i<n-1;i++){
            int j  = i+1 , k = n -1;
            while(j<k){
                int sum = arr[i] + arr[j] +arr[k];
                if(sum == x) return 1;
                else if(sum>x) k--;
                else j++;
            }
        }
        return 0;
    }
};
/*
    MOST OPTIMZIED APPROACH
Expected Time Complexity: O(n^2)
Expected Auxiliary Space: O(1)
*/
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int x)
    {
        //Your Code Here
        if(n<3) return 0;
        int count = 0 ;
        sort(arr,arr+n);
        for(int i=0;i<n-1;i++){
            int j = i+1 , k = n-1;
            while(j<k){
                int sum = arr[i]+arr[j]+arr[k];
                if(sum==x){
                    count++;
                    j++;k--;
                }
                else if(sum>x){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return count;
    }

};