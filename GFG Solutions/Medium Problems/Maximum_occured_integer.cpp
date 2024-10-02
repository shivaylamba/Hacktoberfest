/*
Maximum occured integer
Given n integer ranges, the task is to return the maximum occurring integer in the given ranges. If more than one such integer exists, return the smallest one.
The ranges are in two arrays l[] and r[].  l[i] consists of the starting point of the range and r[i] consists of the corresponding endpoint of the range & a maxx which is the maximum value of r[].
For example, consider the following ranges.
l[] = {2, 1, 3}, r[] = {5, 3, 9)
Ranges represented by the above arrays are.
[2, 5] = {2, 3, 4, 5}
[1, 3] = {1, 2, 3}
[3, 9] = {3, 4, 5, 6, 7, 8, 9}
The maximum occurred integer in these ranges is 3.
Examples :
Input: n = 4, l[] = {1,4,3,1}, r[] = {15,8,5,4}, maxx = 15
Output: 4
Explanation: The given ranges are [1,15] [4, 8] [3, 5] [1, 4]. The smallest number that is most common or appears most times in the ranges is 4.
Input: n = 5, l[] = {1,5,9,13,21}, r[] = {15,8,12,20,30}, maxx = 30
Output: 5
Explanation: The given ranges are [1, 15] [5, 8] [9, 12] [13, 20] [21, 30]. The smallest number that is most common or appears most times in the ranges is 5.
Expected Time Complexity: O(n+maxx).
Expected Auxiliary Space: O(maxx), maxx is maximum element in r[]
Constraints:
1 ≤ n ≤ 106
0 ≤ l[i], r[i] ≤ 106
*/

/*
Time Complexity: O(N + MAX) 
Auxiliary space: O(MAX)
*/
class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int L[], int R[], int maxx) {

        // Your code here
        const int MAX = 1000000;
 int arr[MAX];
    memset(arr, 0, sizeof arr);
 
    // Adding +1 at Li index and subtracting 1
    // at Ri index.
    for (int i = 0; i < n; i++) {
        arr[L[i]] += 1;
        arr[R[i] + 1] -= 1;
    }
 
    // Finding prefix sum and index having maximum
    // prefix sum.
    int msum = arr[0], ind;
    for (int i = 1; i < maxx + 1; i++) {
        arr[i] += arr[i - 1];
        if (msum < arr[i]) {
            msum = arr[i];
            ind = i;
        }
    }
 
    return ind;
    }
};
/*
    BRUTE FORCE (HASH TABALE)
Time Complexity: O(N*M). Here N is the number of ranges and M is the maximum number of elements in any of the ranges.
Auxiliary Space: O(M). For Hash table.
*/
class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

        // Your code here
        map<int,int> map;
        for(int i = 0;i<n;i++){
            for(int j = l[i];j<=r[i];j++){
                map[j]++;
            }
        }
        int maxOcc = 0 , ans =INT_MAX;
        for(auto i:map){
            if(i.second>maxOcc){
                maxOcc = i.second;  ans = i.first;
            }
            else if(i.second==maxOcc){
                ans = min(ans,i.first);
            }
        }
        return ans;
    }
};