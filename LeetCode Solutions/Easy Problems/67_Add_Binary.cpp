/*
67. Add Binary
Given two binary strings a and b, return their sum as a binary string.
Example 1:
Input: a = "11", b = "1"
Output: "100"
Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/
/*
        MOST OPTIMIZED APPROACH
    Time Complexity O(n)
    Space Complexity O(n)
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int i = 0 , j = 0 ;
        string ans = "";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry = 0 ;
        while(i<a.size() || j<b.size() || carry){
                int n1 = 0 , n2 = 0;
                if(i<a.size()) n1 = a[i] - 48 ;
                if(j<b.size()) n2 = b[j] - 48;
                int sum = n1+n2+carry;
                int digit = sum%2;
                carry = sum/2;
                ans.push_back('0'+ digit);
                i++;j++;
        }
         reverse(ans.begin(),ans.end());
        return ans;
    }
};