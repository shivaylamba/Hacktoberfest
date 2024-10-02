/*
912. Sort an Array
Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
Constraints:
1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/
/*
    USING HASHMAP
Time Complexity O(n);
Space Complexity O(n);
*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
     map<int,int> map;
     for(int  i:nums) map[i]++;
     nums.clear();
     for(auto i:map){
        int f = i.first;
        while(map[f]){
                nums.push_back(f);
                map[f]--;
                // if(map[f]==0) map.erase(f);
        }
     }   
     return nums;
    }
};
/*
    USING MERGE SORT
Time Complexity O(n);
Space Complexity O(n);
*/
class Solution {
public:
    vector<int> mergesorted(vector<int>&arr)
    {
        if(arr.size()==1)
        {
            return arr;
        }
        int dividesize=arr.size()/2;
        vector<int>merge1,merge2;
        for(int i=0;i<dividesize;i++)
        {
            merge1.push_back(arr[i]);
        }
        for(int i=dividesize;i<arr.size();i++)
        {
            merge2.push_back(arr[i]);
        }
        merge1=mergesorted(merge1);
        merge2=mergesorted(merge2);
        int ptr1=0,ptr2=0,ptr3=0;
        while(ptr3<arr.size())
        {
            if(ptr1==merge1.size())
            {
                arr[ptr3]=merge2[ptr2];
                ptr2++;
                ptr3++;
                continue;
            }
            if(ptr2==merge2.size())
            {
                arr[ptr3]=merge1[ptr1];
                ptr1++;
                ptr3++;
                continue;   
            }
            if(merge1[ptr1]<merge2[ptr2])
            {
                arr[ptr3]=merge1[ptr1];
                ptr1++;
                ptr3++;
            }
            else
            {
                arr[ptr3]=merge2[ptr2];
                ptr2++;
                ptr3++;
            }
        }
        return arr;
    }
    vector<int> sortArray(vector<int>&nums) 
    {
        return mergesorted(nums);
    }
};
/*
    USING In-Built Sort Function
Time Complexity O(n);
Space Complexity O(n);
*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;

    }
};