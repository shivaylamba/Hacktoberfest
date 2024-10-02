class Solution {
public:
  // First Approach Time Complexity is O(n)
  //                 Space complexity is O(1)
    void leftRotate(int arr[], int n, int d) {
        // code here
       int i = 0 , j = d-1;
       while(i<j){
           swap(arr[i++],arr[j--]);
       }
       i = d , j = n-1;
       while(i<j){
            swap(arr[i++],arr[j--]);

       }
            i = 0, j = n-1;
       while(i<j){
            swap(arr[i++],arr[j--]);

       }
    }
  // Second Approach Time Complexity is O(nlog(n))
  //                 Space complexity is O(1)
    void rotate(vector<int>& nums, int k) {
        int n =nums.size() ;
   k = k%n;
   reverse(nums.begin(),nums.begin() + (n-k));
   reverse(nums.begin() + (n-k) , nums.end());
   reverse(nums.begin(),nums.end());
    }

  // third Approach Time Complexity is O(n)
  //                 Space complexity is O(n)
     void rotate1(vector<int>& nums, int k) {
        int n =nums.size() ;
        vector<int> temp(n);
       for(int i =0;i<n;i++){
             temp[(i+k)%n] = nums[i];
       }
    }
};
/*
Let the array be - 123456789 and k = 4

Step 1 - 12345 6789 ---> 54321 6789

Step 2 - 54321 6789 ---> 54321 9876

Step 3 - 543219876 ---> 678912345

*/