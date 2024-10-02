/*
Longest alternating subsequence
You are given an array arr. Your task is to find the longest length of a good sequence. A good sequence {x1, x2, .. xn} is an alternating sequence if its elements satisfy one of the following relations :

1.  x1 < x2 > x3 < x4 > x5. . . . . and so on
2.  x1 >x2 < x3 > x4 < x5. . . . . and so on

Examples:

Input: arr= [1, 5, 4]
Output: 3
Explanation: The entire sequenece is a good sequence.
Input: arr= [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
Output: 7
Explanation: There are several subsequences that achieve this length. 
One maximum length good subsequences is [1, 17, 10, 13, 10, 16, 8].
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 <= nums.size() <= 105 
1 <= nums[i] <= 104 
*/
/*
    With DP
Time Complexity: O(N2) 
Auxiliary Space: O(N), since N extra space has been taken
*/
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
    /*las[i][0] = Length of the longest
        alternating subsequence ending at
        index i and last element is greater
        than its previous element
    las[i][1] = Length of the longest
        alternating subsequence ending
        at index i and last element is
        smaller than its previous element */
        int n = arr.size();
    int las[n][2];
 
    // Initialize all values from 1
    for (int i = 0; i < n; i++)
        las[i][0] = las[i][1] = 1;
 
    // Initialize result
    int res = 1;
 
    // Compute values in bottom up manner
    for (int i = 1; i < n; i++) {
 
        // Consider all elements as
        // previous of arr[i]
        for (int j = 0; j < i; j++) {
 
            // If arr[i] is greater, then
            // check with las[j][1]
            if (arr[j] < arr[i]
                && las[i][0] < las[j][1] + 1)
                las[i][0] = las[j][1] + 1;
 
            // If arr[i] is smaller, then
            // check with las[j][0]
            if (arr[j] > arr[i]
                && las[i][1] < las[j][0] + 1)
                las[i][1] = las[j][0] + 1;
        }
 
        // Pick maximum of both values at index i
        if (res < max(las[i][0], las[i][1]))
            res = max(las[i][0], las[i][1]);
    }
    return res;
        
    }
};
/*
    Without DP
Time Complexity o(n)
Time Complexity o(1)
*/
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
    int inc = 1,dec = 1, n = arr.size();
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) inc = dec + 1;
        else if (arr[i] < arr[i - 1])  dec = inc + 1;

    }
    return max(inc, dec);
        
    }
};