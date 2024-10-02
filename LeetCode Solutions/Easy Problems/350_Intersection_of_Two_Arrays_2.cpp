/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/
/*
    MOST OPTIMIZED APPROACH
Time Complexity O(n)
Space Complexity O(n)
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]]>0){
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }

        return ans;
    }
};
//-----------------------------------------------------------------------------------------------------------------------------//
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        for(int i :nums1)   map[i]++;
        nums1.clear();
        for(int i:nums2){
            if(map.find(i)!=map.end()){
                nums1.push_back(i);
                map[i]--;
                if(map[i]==0) map.erase(i);
            }
        }
        return nums1;
    }
};
//-----------------------------------------------------------------------------------------------------------------------------//
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> v;
        for(int i=nums1.size()-1; i>=0; i--){
            mp[nums1[i]] ++;
            nums1.pop_back();
        }
        for(int i=nums2.size()-1; i>=0; i--){
            if(mp.find(nums2[i]) != mp.end() and mp[nums2[i]] > 0){
                v.push_back(nums2[i]);
                mp[nums2[i]] --;
            }
            nums2.pop_back();
        }
        return v;
    }
};
/*
    LEAST OPTIMIZED APPROACH
Time Complexity O(n*log(n))
Space Complexity O(n)
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
             sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> ans;
        int i =0 , j =0;
        while(i<nums1.size() && j< nums2.size()){
            if(nums1[i]==nums2[j]){
               ans.push_back(nums1[i]);
               i++;j++;
            }
            else if(nums1[i]<nums2[j]){
                          i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};