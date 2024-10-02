/*
Kth smallest element
Given an array arr[] and an integer K where K is smaller than size of array,
 the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
Note :-  l and r denotes the starting and ending index of the array.
Your Task:
You don't have to read input or print anything. 
Your task is to complete the function kthSmallest() which takes 
the array arr[], integers l and r denoting the starting and ending 
index of the array and an integer K as input and returns the Kth smallest element.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(log(n))
Constraints:
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N
*/
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        map<int,int> map;
        int ans  =  -1;
        for(int i:arr) map[i]++;
        for(auto i:map){
            k--;
            if(k==0) {ans = i.first; break;}
        }
        return ans;
    }
};

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        sort(arr,arr+(r+1));
        return arr[k-1];
    }
};
