/*
Median of 2 Sorted Arrays of Different Sizes
Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.

Example 1:

Input:
m = 3, n = 4
array1[] = {1,5,9}
array2[] = {2,3,6,7}
Output: 5
Explanation: The middle element for
{1,2,3,5,6,7,9} is 5
Example 2:

Input:
m = 2, n = 4
array1[] = {4,6}
array2[] = {1,2,3,5}
Output: 3.5
Your Task:
The task is to complete the function MedianOfArrays() that takes array1 and array2 as input and returns their median. 

Can you solve the problem in expected time complexity?

Expected Time Complexity: O(min(log n, log m)).
Expected Auxiliary Space: O((n+m)/2).

Constraints: 
0 ≤ m,n ≤ 106
1 ≤ array1[i], array2[i] ≤ 109
*/
/*
    MOST MOST OPTIMIZED APPROACH
    Median of two sorted arrays of different sizes using Binary Search:
    Time Complexity: O(min(log M, log N)): Since binary search is being applied on the smaller of the 2 arrays
    Auxiliary Space: O(1)
*/
// Method to find median
double Median(vector<int>& A, vector<int>& B)
{
    int n = A.size();
    int m = B.size();
    if (n > m)
        return Median(B, A); // Swapping to make A smaller

    int start = 0;
    int end = n;
    int realmidinmergedarray = (n + m + 1) / 2;

    while (start <= end) {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA
            = (leftAsize > 0)
                  ? A[leftAsize - 1]
                  : INT_MIN; // checking overflow of indices
        int leftB
            = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
        int rightA
            = (leftAsize < n) ? A[leftAsize] : INT_MAX;
        int rightB
            = (leftBsize < m) ? B[leftBsize] : INT_MAX;

        // if correct partition is done
        if (leftA <= rightB and leftB <= rightA) {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB)
                        + min(rightA, rightB))
                       / 2.0;
            return max(leftA, leftB);
        }
        else if (leftA > rightB) {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return 0.0;
}
/*
    Most OPTIMIZED APPROACH
    Time Complexity: O(M + N). To merge both arrays O(M+N) time is needed.
    Auxiliary Space: O(1). No extra space is required.
*/
class Solution{
    public:
    double MedianOfArrays(vector<int>& ar1, vector<int>& ar2)
    {
        // Your code goes here
        int  n = ar1.size() , m = ar2.size();
        int i = 0 , j = 0;
        int m1 = -1 , m2 = -1  ,count = 0 ;
        for(count = 0 ;count<=(m+n)/2 ;count++){
            m2 = m1;
        if (i != n && j != m) {
            m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
        }
        else if (i < n) {
            m1 = ar1[i++];
        }
        // for case when j<m,
        else {
            m1 = ar2[j++];
        }
        }
         if ((m + n) % 2 == 1) {
        return m1;
    }
    else {
        return (double)(m1 + m2) / 2;
    }
    
    }
};
/*
    OPTIMIZED APPROACH
    Time Complexity O(n+m);
    Space Complexity O(n+m);
*/
class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        vector<int>ans;
        int i = 0 , j = 0 ;
        while(i<array1.size() && j<array2.size()){
            int n1 = array1[i] , n2 = array2[j];
            if(n1>n2){
                ans.push_back(n2);
                j++;
            }
            else if(n1<n2){
                ans.push_back(n1);
                i++;
            }
            else if(n1==n2){
                ans.push_back(n1);
                ans.push_back(n2);
                i++;j++;
            }
        }
        while(i<array1.size()){
            ans.push_back(array1[i++]);
        }
        while(j<array2.size()){
            ans.push_back(array2[j++]);
        }
        int n = ans.size();
        if(n%2!=0) return (double)ans[n/2];
        else return (double)(ans[(n-1)/2] + ans[n/2])/2.0;
    
    }
};