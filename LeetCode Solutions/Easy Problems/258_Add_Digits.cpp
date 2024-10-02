/*
258. Add Digits
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
Example 1:
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:
Input: num = 0
Output: 0
Constraints:
0 <= num <= 231 - 1
Follow up: Could you do it without any loop/recursion in O(1) runtime?
*/
/*------------Most Optimized Approach---------------------*/
//  Time Complexity O(1)
class Solution
{
public:
  int addDigits(int num)
  { if(num==0)
  return 0;
   if( num%9==0)
return 9;
else
return num%9;
  }
};
/*------------ Optimized Approach---------------------*/
//  Time Complexity O(n)
class Solution {
public:
    int addDigits(int num) 
    {
        if (num < 10)
        {
            return num;
        }    

        while (num > 9)
        {
            num = addDigits(num / 10) + addDigits(num % 10);
        }

        return num;
    }
};
/*------------Brute Froce Approach---------------------*/
class Solution {
public:
    int addDigits(int num) {
        int res = 0;
        if(num==0) return res;
        while(1){
            int ans = 0;
            while(num>0){
                int ld = num%10;
                ans  += ld;
                num/=10;
            }
            if(ans<10){
                res=ans;
                break;
            }
            else{
                num = ans;
            }
        }
        return res;
    }
};