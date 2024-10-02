/*
Validate an IP Address
You are given a string str in the form of an IPv4 Address. Your task is to validate an IPv4 Address, if it is valid return true otherwise return false.
IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1
A valid IPv4 Address is of the form x1.x2.x3.x4 where 0 <= (x1, x2, x3, x4) <= 255. Thus, we can write the generalized form of an IPv4 address as (0-255).(0-255).(0-255).(0-255)
Note: Here we are considering numbers only from 0 to 255 and any additional leading zeroes will be considered invalid.
Examples :
Input: str = 222.111.111.111
Output: true
Explanation: Here, the IPv4 address is as per the criteria mentioned and also all four decimal numbers lies in the mentioned range.
Input: str = 5555..555
Output: false
Explanation: 5555..555 is not a valid. IPv4 address, as the middle two portions are missing.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
Constraints:
1<=str.length() <=15
*/
// User function Template for C++
class Solution {
  public:
int isValid(string str) {
        // code here
        int temp=-1,count=0,index=-1;
        for(int i=0;i<str.length();i++){
            if(str[i]=='.'){
                count++;
                if(temp<0 or temp>255)return false;
                if(temp!=0 and str[index+1]=='0')return false;
                temp=-1;
                index=i;
            }
            else{
                if(temp==-1)temp=0;
                temp=temp*10+(str[i]-'0');
            }
        }
        if(temp<0 or temp>255 or count!=3)return false;
        if(temp!=0 and str[index+1]=='0')return false;
        return true;
    }
};