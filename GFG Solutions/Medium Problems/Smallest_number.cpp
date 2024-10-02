/*
Smallest number
Given two integers s and d. The task is to find the smallest number such that the sum of its digits is s and the number of digits in the number are d. Return a string that is the smallest possible number. If it is not possible then return -1.

Examples:

Input: s = 9, d = 2
Output: 18 
Explanation: 18 is the smallest number possible with the sum of digits = 9 and total digits = 2.
Input: s = 20, d = 3 
Output: 299 
Explanation: 299 is the smallest number possible with the sum of digits = 20 and total digits = 3.
Expected Time Complexity: O(d)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ s ≤ 100
1 ≤ d ≤ 6
*/
// User function Template for C++
/*
    APPROACH - 1
Time Complexity: O(d)
Space Complexity: O(d)
*/
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
       if(s==1){
           if(d==1) return "1"; 
       }
       if(s > 9*d) return "-1";
 string str = "";
    s-=1;
    for(int i = d-1;i>0;i--){
        if(s>9){    str = to_string(9) + str; s-=9;   }
        else{  str = to_string(s) +str; s=0;    }   
    }
    str = to_string(s+1) +str;
    return str;
        
    }
};
/*
    APPROACH - 2
Time Complexity: O(d)
Space Complexity: O(d)
*/
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
       if(s==1){
           if(d==1) return "1"; 
       }
       if(s > 9*d) return "-1";
    vector<int> res(d);
    s-=1;
    for(int i = d-1;i>0;i--){
        if(s>9){    res[i] = 9; s-=9;   }
        else{  res[i] = s; s=0;    }   
    }
    res[0] = s+1;
    string str = "";
    for(int i:res) str+=to_string(i);
    return str;
        
    }
};