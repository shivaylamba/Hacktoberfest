/*
Count the elements
Given two arrays a and b both of size n. Given q queries in an array query each having a positive integer x denoting an index of the array a. For each query, your task is to find all the elements less than or equal to a[x] in the array b.

Example 1:

Input:
n = 3
a[] = {4,1,2}
b[] = {1,7,3}
q = 2
query[] = {0,1}
Output : 
2
1
Explanation: 
For 1st query, the given index is 0, a[0] = 4. There are 2 elements(1 and 3) which are less than or equal to 4.
For 2nd query, the given index is 1, a[1] = 1. There exists only 1 element(1) which is less than or equal to 1.
Example 2:

Input:
n = 4
a[] = {1,1,5,5}
b[] = {0,1,2,3}
q = 4
query[] = {0,1,2,3}
Output : 
2
2
4
4
Explanation: 
For 1st query and 2nd query, the given index is 0 and 1 respectively, a[0] = a[1] = 1. There are 2 elements(0 and 1) which are less than or equal to 1. 
For 3rd query and 4th query, the given index is 2 and 3 respectively, a[2] = a[3] = 5. All the 4 elements are less than or equal to 5.   
Your Task:
You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function countElements() that takes array a and b of size n, and array query of size q as parameters and returns an array that contains the answer to the corresponding queries. 

Expected Time Complexity: O(n+q+maximum of a and b).

Expected Auxiliary Space: O(maximum of a and b).

Constraints:
1 ≤ q ≤ n ≤ 105
1 ≤ a[i], b[i] ≤ 105
0 ≤ query[i] < n
*/
// User function Template for C++
//   Most Optimized Approach
//  Time Complexity O(n)
//  Space Complexity O(n)
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        int maxa = INT_MIN;
        for(int x:b){ maxa = max(maxa,x);}
        vector<int> heap(maxa+1,0);
        for(int x:b){   heap[x]++;   }
        for(int i = 1 ; i<=maxa;i++){ heap[i] +=heap[i-1]; } // saving all the previous result in the current heap index
        vector<int> ans;
        for(int i = 0 ; i <q;i++){
            if(a[query[i]] > maxa){ // if the current element of a is  greater than the max element 
                ans.push_back(n);
            }
            else{
                // take a[query[i]] as an index in the heap array to chcek how many element in 
                // smaller or equal to the a[query[i]]
                ans.push_back(heap[a[query[i]]]);
            }
        }
        return ans;
}
};
//   Optimized Approach
//  Time Complexity O(n*m)
//  Space Complexity O(n)
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        vector<int> ans(query.size(),0);
        int i  =0 ;
        while(i<query.size()){
            for(int x:b){
                if(a[query[i]]>=x){ans[i]++;}
            }
            i++;
        }
        return ans;
    }
};