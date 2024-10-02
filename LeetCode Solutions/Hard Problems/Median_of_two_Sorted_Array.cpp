/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
// Time Complexity O(nlog(n))
// Space Complexity O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int mid = (nums1.size()-1)/2;
        if(nums1.size()%2==0){
            ans = (double)(nums1[mid] + nums1[mid+1])/2;
        }
        else{
            ans =  (double)nums1[mid];
        }
        return ans;
    }
};
// Time Complexity O(n)
// Space Complexity O(n)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        vector<int>ans;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
               ans.push_back(nums2[j]); 
               j++;
            }
        }
        while(i<nums1.size()){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }
        int st=0;
        int end=ans.size()-1;
        int mid= st+(end-st)/2;
        float res;
        if(ans.size() % 2 == 0){
            res= (double)(ans[mid]+ans[mid+1])/2;
        }
        else{
            res=ans[mid];
        }
        return res;
    }
};