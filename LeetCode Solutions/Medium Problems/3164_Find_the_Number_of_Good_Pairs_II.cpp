/*
3164. Find the Number of Good Pairs II
You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively. You are also given a positive integer k.
A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k (0 <= i <= n - 1, 0 <= j <= m - 1).
Return the total number of good pairs.
Example 1:
Input: nums1 = [1,3,4], nums2 = [1,3,4], k = 1
Output: 5
Explanation:
The 5 good pairs are (0, 0), (1, 0), (1, 1), (2, 0), and (2, 2).
Example 2:
Input: nums1 = [1,2,4,12], nums2 = [2,4], k = 3
Output: 2
Explanation:
The 2 good pairs are (3, 0) and (3, 1).
*/
/*
    OPTMIZED APPROACH HASHMAP
    Time Complexity O(n)
    Space Complexity O(n)
*/
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<long long,long long> a ,b;
        long long maxa = INT_MIN;
        for(long long x:nums1){   a[x]++; maxa = max(maxa,x); }
        for(long long x:nums2){   b[x*k]++; }

        long long count  =0 ;
        for(auto x:b){
            for(long long i =1;x.first * i <= maxa ;++i){
                if(a.find(x.first * i) != a.end()){
                    count+= x.second*a[x.first *i];
                }
            }
        }
        return count;
    }
};