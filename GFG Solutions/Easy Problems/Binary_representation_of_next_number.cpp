/*
Binary representation of next number
Given a binary representation in the form of a string(s) of a number n, the task is to find a binary representation of n+1.
Note: Output binary string should not contain leading zeros.
Example 1:
Input: s = "10"
Output: 11
Explanation: "10" is the binary representation of 2 and binary representation of 3 is "11"
Example 2:
Input: s = "111"
Output: 1000
Explanation: "111" is the binary representation of 7 and binary representation of 8 is "1000"
Your Task:  
You don't need to read input or print anything. Complete the function binaryNextNumber()which takes s as input parameter and returns the string.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n) to store resultant string  
Constraints:
1 <= n <= 105
*/
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        string str = "";
        int i =0;
        while(s[i]=='0'){
            s.erase(i,1);
        }
        if(s.size()==0) return "1";
        int carry = 0 ;
        i = s.size()-1 ;
        int j=s.size()-1;
        while(carry || i>=0){
            int n1 = 0 ;
            if(i>=0)  n1 = s[i] - 48;
            
            int sum = carry+n1;
            if(j==i){   sum+=1;   }
            
            int digit = sum%2;
            str.push_back(digit+48);
            carry = sum/2;
            i--;
        }
        reverse(str.begin(),str.end());
        return str;
        
    }
};