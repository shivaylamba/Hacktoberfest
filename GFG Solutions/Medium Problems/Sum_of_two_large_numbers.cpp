/*
Sum of two large numbers
Given two strings denoting non-negative numbers X and Y. Calculate the sum of X and Y.
Example 1:
Input:
X = "25", Y = "23"
Output:
48
Explanation:
The sum of 25 and 23 is 48.
Example 2:
Input:
X = "2500", Y = "23"
Output:
2523
Explanation:
The sum of 2500 and 23 is 2523.
Your Task:
Your task is to complete the function findSum() which takes two strings as inputs and returns the string without leading zeros. You do not need to take any input or print anything.
Expected Time Complexity: O(|X| + |Y|)
Expected Auxiliary Space: O(1)
Constraints:
1 <= |X|, |Y| <= 105
*/
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        int i = 0 , j = 0;
        while(X[i]=='0'){
            X.erase(i,1);
        }
        while(Y[j]=='0'){
            Y.erase(j,1);
        }
        string ans = "";
        i =X.size()-1 , j = Y.size()-1 ;
        int carry = 0;
        while(i>=0 || j>=0 || carry){
            int n1 = 0 , n2 = 0 ;
            if(i>=0) n1 = X[i] - 48;
            if(j>=0) n2 = Y[j] - 48;
            int sum = n1 +n2 + carry;
            int digit = sum%10;
            ans.push_back(48 + digit);
            carry = sum/10;
            i--;j--;
        }
        if(ans.size()==0)return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};