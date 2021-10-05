class Solution {
public:
    
    double func(vector<int>& nums1, int n1, vector<int>& nums2, int n2)
    {
        int begin1=0;
        int end1=n1;
        while(begin1 <= end1)
        {
        int i1 = (begin1 + end1) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;
            
            int min1 = (i1==n1) ? INT_MAX : nums1[i1];
            int max1 = (i1==0)  ? INT_MIN : nums1[i1-1];
            
            int min2 = (i2==n2) ? INT_MAX : nums2[i2];
            int max2 = (i2==0)  ? INT_MIN : nums2[i2-1];
            
             if((max1<=min2) && (max2<=min1) ){
                    if((n1+n2)%2==0){
                return ((double) (max(max1,max2) + min(min1, min2)) / 2) ;
            }else{
                return ((double) max(max1, max2));
            }
        }
        else if(max1>min2){
            end1 = i1-1;
        }else{
            begin1 = i1+1;
        }
     }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2=nums2.size();
        if(n2 > n1){
           return func(nums1,n1,nums2,n2); 
        }
        else{
            return func(nums2,n2,nums1,n1);
        }
    }
};