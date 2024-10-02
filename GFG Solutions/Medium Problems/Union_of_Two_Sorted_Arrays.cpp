/*
Union of Two Sorted Arrays
Given two sorted arrays of size n and m respectively, find their union. The Union of two arrays can be defined as the common and distinct elements in the two arrays. 

Example 1:

Input: 
n = 5, arr1[] = {1, 2, 3, 4, 5}  
m = 5, arr2 [] = {1, 2, 3, 6, 7}
Output: 
1 2 3 4 5 6 7
Explanation: 
Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Example 2:

Input: 
n = 5, arr1[] = {2, 2, 3, 4, 5}  
m = 5, arr2[] = {1, 1, 2, 3, 4}
Output: 
1 2 3 4 5
Explanation: 
Distinct elements including both the arrays are: 1 2 3 4 5.
Example 3:

Input:
n = 5, arr1[] = {1, 1, 1, 1, 1}
m = 5, arr2[] = {2, 2, 2, 2, 2}
Output: 
1 2
Explanation: 
Distinct elements including both the arrays are: 1 2.
Your Task: 
You do not need to read input or print anything. Complete the function findUnion() that takes two arrays arr1[], arr2[], and their size n and m as input parameters and returns a list containing the union of the two arrays.

Expected Time Complexity: O(n+m).
Expected Auxiliary Space: O(n+m).

Constraints:
1 <= n, m <= 105
-109 <= arr1[i], arr2[i] <= 109
*/


/*
        Union of Two-Sorted Arrays by Handling duplicates in any of the arrays:
Time Complexity : O(m + n)
Auxiliary Space: O(1)
*/
class Solution{
    public:
void next_distinct(const vector<int> &arr, int &x) // Moving to next distinct element
{
  // vector CAN be passed by reference to avoid unnecessary copies.
  // x(index) MUST be passed by reference so to reflect the change in the original index parameter
   
  /* Checks whether the previous element is equal to the current element,
       if true move to the element at the next index else return with the current index
  */
    do
    {
        ++x;
    } while (x < arr.size() && arr[x - 1] == arr[x]);
}
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        int j = 0  , i = 0 ;
        while(i<n  && j<m){
            if(arr1[i] > arr2[j]){
                ans.push_back(arr2[j]);
            next_distinct(arr2, j); // Incrementing j to next distinct element
            }
            else if(arr1[i] < arr2[j]){
                ans.push_back(arr1[i]);
            next_distinct(arr1, i); // Incrementing i to next distinct element
            }
            else if(arr1[i]==arr2[j]){
               ans.push_back(arr1[i]);
            next_distinct(arr1, i); // Incrementing i to next distinct element
            next_distinct(arr2, j); // Incrementing j to next distinct element
            }
        }
        while(i<n){
            ans.push_back(arr1[i]);
            next_distinct(arr1, i); // Incrementing i to next distinct element
        }
        while(j<m){
            ans.push_back(arr2[j]);
            next_distinct(arr2, j); // Incrementing j to next distinct element
        }
        return ans;
    }
};



/*
        Two Pointer common Duplicate in the Both array
Time Complexity : O(m + n)
Auxiliary Space: O(1)
*/
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        int j = 0  , i = 0 ;
        while(i<n  && j<m){
            if(arr1[i] > arr2[j]){
                ans.push_back(arr2[j++]);
            }
            else if(arr1[i] < arr2[j]){
                ans.push_back(arr1[i++]);
            }
            else if(arr1[i]==arr2[j]){
               ans.push_back(arr1[i++]);
                j++;
            }
        }
        while(i<n){
            ans.push_back(arr1[i++]);
        }
        while(j<m){
            ans.push_back(arr2[j++]);
        }
        return ans;
    }
};



/*
  Using SET
Time Complexity: O(m*log(m) + n*log(n)), where ‘m’ and ‘n’ are the size of the arrays
Auxiliary Space: O(m + n)
*/
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        set<int> s;
        for(int i = 0 ; i<n;i++){
            s.insert(arr1[i]);
        }
        for(int i = 0 ; i<m;i++){
            s.insert(arr2[i]);
        }
        vector<int> vec(s.begin(),s.end());
        return vec;
    }
};



/*
      Using map
Time Complexity:O(m*log(m) + n*log(n)), where ‘m’ and ‘n’ are the size of the arrays
Auxiliary Space: O(m + n)
*/
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        map<int,int> f;
        for(int i=0;i<n;i++){
            if(f.find(arr1[i]) !=f.end()){
                f[arr1[i]]++;
            }
            else{
                f[arr1[i]] = 1;
            }
        }
         for(int i=0;i<m;i++){
            if(f.find(arr2[i]) !=f.end()){
                f[arr2[i]]++;
            }
            else{
                f[arr2[i]] = 1;
            }
        }
        vector<int> vec;
        for(auto  i:f){
            vec.push_back(i.first);
        }
        return vec;
    }
};
