/*
Sum of Middle elements of two sorted arrays
Given 2 sorted integer arrays arr1 and arr2 of the same size. Find the sum of the middle elements of two sorted arrays arr1 and arr2.

Examples:

Input: arr1 = [1, 2, 4, 6, 10], arr2 = [4, 5, 6, 9, 12]
Output: 11
Explanation: The merged array looks like [1, 2, 4, 4, 5, 6, 6, 9, 10, 12]. Sum of middle elements is 11 (5 + 6).
Input: arr1 = [1, 12, 15, 26, 38], arr2 = [2, 13, 17, 30, 45]
Output: 32
Explanation: The merged array looks like [1, 2, 12, 13, 15, 17, 26, 30, 38, 45]. Sum of middle elements is 32 (15 + 17).
Expected Time Complexity: O(log n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr1.size() == arr2.size() <= 103
1 <= arr1[i] <= 106
1 <= arr2[i] <= 106
*/
/*
    MOST OPTMIZED APPROACH (BINARY SEARCH)
Time Complexity O(max(n,m))
Space Complexity O(n+m)
*/
//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int n  = arr1.size();
     int low = 0, high = n;

    while (low <= high) {
        // Partition points in both arrays
        int cut1 = (low + high) / 2;
        int cut2 = n - cut1;

        // Elements around the partition points
        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == n) ? INT_MAX : arr2[cut2];

        // Check if we have found the correct partition
        if (l1 <= r2 && l2 <= r1) {
            // Return the sum of the middle elements
            return max(l1, l2) + min(r1, r2);
        } else if (l1 > r2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    // This case will never occur for valid input
    return 0;
    }
};
/*
    OPTMIZED APPROACH
Time Complexity O(max(n,m))
Space Complexity O(n+m)
*/
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        vector<int> ans;
        int i =0 , j = 0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]>arr2[j]){ ans.push_back(arr2[j++]);}
            else if(arr1[i]<arr2[j]){ ans.push_back(arr1[i++]);}
            else if(arr1[i]==arr2[j]){ ans.push_back(arr1[i++]) ; ans.push_back(arr2[j++]);}
        }
        while(i<arr1.size()) ans.push_back(arr1[i++]);
        while(j<arr2.size()) ans.push_back(arr2[j++]);
        int mid  = ans.size()/2;
        return ans[mid]+ans[mid-1];

    }
};