/*
Equilibrium Point
Given an array A of n non negative numbers. The task is to find the first equilibrium point in an array. Equilibrium point in an array is an index (or position) such that the sum of all elements before that index is same as sum of elements after it.

Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 

Example 1:

Input: 
n = 5 
A[] = {1,3,5,2,2} 
Output: 
3 
Explanation:  
equilibrium point is at position 3 as sum of elements before it (1+3) = sum of elements after it (2+2). 
Example 2:

Input:
n = 1
A[] = {1}
Output: 
1
Explanation:
Since there's only element hence its only the equilibrium point.
Your Task:
The task is to complete the function equilibriumPoint() which takes the array and n as input parameters and returns the point of equilibrium. 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 105
0 <= A[i] <= 109
*/
/*
        MOST OPTIMIZED APPROACH
Equilibrium index of an array using Prefix-Sum:
    Time Complexity: O(N)
    Auxiliary Space: O(1)
*/
int equilibrium(int arr[], int n)
{
    int sum = 0; // initialize sum of whole array
    int leftsum = 0; // initialize leftsum
 
    /* Find sum of the whole array */
    for (int i = 0; i < n; ++i)
        sum += arr[i];
 
    for (int i = 0; i < n; ++i) {
        sum -= arr[i]; // sum is now right sum for index i
 
        if (leftsum == sum)
            return i;
 
        leftsum += arr[i];
    }
 
    /* If no equilibrium index found, then return 0 */
    return -1;
}
/*
Equilibrium index of an array using Prefix-Sum:
    Time Complexity: O(N)
    Auxiliary Space: O(N)
*/
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int pSum[n] = {0} , sSum[n]={0};
        pSum[0]=a[0];
        for(int i=1;i<n;i++){
            pSum[i] = pSum[i-1] + a[i]; 
        }
         sSum[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            sSum[i] = sSum[i+1] + a[i]; 
        }
        for(int i=0;i<n;i++){
            if(pSum[i]==sSum[i]){
                return i+1;
            }
        }
        return -1;
    }

};


/*
    Naive approach:
    Time Complexity: O(N2)
    Auxiliary Space: O(1)
*/
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int lSum = 0  ,rSum = 0;
        for(int i = 0 ; i<n;i++){
            lSum = 0;
            for(int j = 0;j<i;j++){
                lSum+=a[j];
            }
            rSum=0;
            for(int j =i+1;j<n;j++){
                rSum+=a[j];
            }
            if(lSum==rSum)return i+1;
        }
        return -1;
    }

};