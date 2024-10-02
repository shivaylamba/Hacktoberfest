/*
Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not. Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) of elements may be different though.
Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.
Example 1:
Input:
N = 5
A[] = {1,2,5,4,0}
B[] = {2,4,5,0,1}
Output: 1
Explanation: Both the array can be 
rearranged to {0,1,2,4,5}
Example 2:
Input:
N = 3
A[] = {1,2,5}
B[] = {2,4,15}
Output: 0
Explanation: A[] and B[] have only 
one common value.
Your Task:
Complete check() function which takes both the given array and their size as function arguments and returns true if the arrays are equal else returns false.The 0 and 1 printing is done by the driver code.
Expected Time Complexity : O(N)
Expected Auxilliary Space : O(N)
Constraints:
1<=N<=107
1<=A[],B[]<=1018
*/
/*
    USING HASHMAP
Time Complexity O(n)
Space Complexity O(n)
*/
class Solution {
  public:
    // Function to check if two arrays are equal or not.
    bool check(vector<int>& arr1, vector<int>& arr2) {
        // code here
        unordered_map<int,int>  map;
        for(int i:arr1) map[i]++;
        for(int i:arr2){
            if(map[i]) map[i]--;
            if(map[i]==0) map.erase(i);
        }
        return map.size()==0;
    }
};
/*
    USING HASHMAP
Time Complexity O(n)
Space Complexity O(n)
*/
class Solution{
    public:
    bool check(vector<ll> A, vector<ll> B, int N) {
        //code here
unordered_map<ll,ll>umap;
for(int i = 0 ; i<N ;i++){
         umap[A[i]]++;
}
for(int i = 0 ;i<N;i++){
    if(umap.find(B[i])==umap.end()){
      return false;
    }
    if(umap[B[i]]==0){
        return false;
    }
    umap[B[i]]--;
}
return true;
    }
/*
    USING INBUILD SORTING METHOD
Time Complexity O(n*log(n))
Space Complexity O(n)
*/
bool areEqual(int arr1[], int arr2[], int N, int M)
{
    // If lengths of array are not equal means
    // array are not equal
    if (N != M)
        return false;
 
    // Sort both arrays
    sort(arr1, arr1 + N);
    sort(arr2, arr2 + M);
 
    // Linearly compare elements
    for (int i = 0; i < N; i++)
        if (arr1[i] != arr2[i])
            return false;
 
    // If all elements were same.
    return true;
}
};
