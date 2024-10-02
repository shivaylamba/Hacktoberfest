/*
Segregate 0s and 1s
Given an array arr consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.
Examples :
Input: arr[] = [0, 0, 1, 1, 0]
Output: [0, 0, 0, 1, 1]
Explanation:  After segregation, all the 0's are on the left and 1's are on the right. Modified array will be [0, 0, 0, 1, 1].
Input: arr[] = [1, 1, 1, 1]
Output: [1, 1, 1, 1]
Explanation: There are no 0s in the given array, so the modified array is [1, 1, 1, 1]
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 1
*/
/*
   TWO POINTER APPROACH
Time Complexity : O(n)
Auxiliary Space: O(1)
*/
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int i = 0 , j = arr.size()-1;
        while(i<j){
            while(arr[i]==0 && i<j) i++;
            while(arr[j]==1 && i<j) j--;
            if(arr[i]==1 && arr[j]==0) swap(arr[i++],arr[j--]);
        }
    }
};
/*
    Method 1 (Count 0s or 1s) 
Time Complexity : O(2n)  ≅ O(n)
Auxiliary Space: O(1)
*/

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int zero = 0 , one= 0 ;
        for(int i:arr){
            if(i) one++;
            else zero++;
        }
        for(int i=0;i<arr.size();i++){
            if(zero){ arr[i] = 0 ; zero--;}
            else{   arr[i] =1 ; one--;}
        }
    }
};