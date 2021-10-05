class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // we start moving from the end toward the beginning
        // take advantage of the point that the arrays are already sorted.
        int a = m - 1 ; //last index of first array
        int b = n - 1 ; //last index of second array
        // a third index for iterating in the entire first array
        int index = m + n - 1;
        while( a >= 0 && b >=0){
            if(nums1[a] < nums2[b]){
                nums1[index--] = nums2[b--];
            }
            else {
                nums1[index--] = nums1[a--];
            }
        }
        // if a is bigger in size, then no worries, because in the end we return that only
        while(b>=0)
            nums1[index--]=nums2[b--];
        // simply copying all the other elements of b into a
    }
};