/*
Given an integer x, find the square root of x. If x is not a perfect square, 
then return floor(√x).
Example 1:
Input:
x = 5
Output: 2
Explanation: Since, 5 is not a perfect 
square, floor of square_root of 5 is 2.
Example 2:
Input:
x = 4
Output: 2
Explanation: Since, 4 is a perfect 
square, so its square root is 2.
Your Task:
You don't need to read input or print anything. The task is 
to complete the function floorSqrt() which takes x as the input parameter and return its square root.
Note: Try Solving the question without using the sqrt function. The value of x>=0.
Expected Time Complexity: O(log N)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ x ≤ 107
*/
//{ Driver Code Starts
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long int i=0, j = x , ans =-1;
        if(x==0) return 0;
        if(x==1) return 1;
        else{
            long long mid = i+(j-i)/2;
            while(i<=j){
                if(pow(mid,2)==x){
                    return mid;
                }
                else if(pow(mid,2)<x){
                    ans= mid;
                    i =mid+1;
                }
                else if(pow(mid,2)>x){
                    j = mid-1;
                }
                mid = i+(j-i)/2;
            }
        }
        return ans;
    }
};
