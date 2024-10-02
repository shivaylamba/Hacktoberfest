/*
Swapping pairs make sum equal
Given two arrays of integers a[] and b[] of size n and m, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

Note: Return 1 if there exists any such pair otherwise return -1.

Example 1:

Input: n = 6, m = 4, a[] = {4, 1, 2, 1, 1, 2}, b[] = (3, 6, 3, 3)
Output: 1
Explanation: Sum of elements in a[] = 11, Sum of elements in b[] = 15, To get same sum from both arrays, we can swap following values: 1 from a[] and 3 from b[]
Example 2:

Input: n = 4, m = 4, a[] = {5, 7, 4, 6}, b[] = {1, 2, 3, 8}
Output: 1
Explanation: We can swap 6 from array a[] and 2 from array b[]
Expected Time Complexity: O(mlogm+nlogn).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ n, m ≤ 106
0 <= a[i], b[i] <= 105
*/
/*
        OPTIMZED APPROACH;
    Time Complexity O(n^log(n) + m^log(m));
    Space Complexity O(1)
*/
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
      // Your code goes here
        int suma=0, sumb=0;
        for(int i=0;i<n;i++) suma+=a[i];
        for(int i=0;i<m;i++) sumb+=b[i];
        
        if((suma-sumb)%2!=0) return -1;
        int target=(suma-sumb)/2;
        int i=0, j=0;
        sort(a, a+n);
        sort(b, b+m);
        while(i<n && j<m){
            int diff=a[i]-b[j];
            if(diff==target) return 1;
            else if(diff<target) i++;
            else j++;
        }
        return -1;
        
    }
};
/*
    BRUTE FORCE;
Time Complexity O(n^2)
Space Complexity O(1)
*/
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int sum1 = 0 , sum2 = 0;
        for(int i = 0 ; i <n;i++){  sum1+=a[i]; }
        for(int i = 0 ; i <m;i++){  sum2+=b[i]; }
        int newsum1   , newsum2 ,x, y;
        for(int i = 0 ; i<n;i++){
            for(int j = 0 ;j<m;j++){
                newsum1 = sum1 - a[i]+b[j];
                newsum2 = sum2 + a[i]-b[j];
                if(newsum1 == newsum2) return 1;
            }
        }
        return -1;
    }
};