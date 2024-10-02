/*
Compare two fractions
You are given a string str containing two fractions a/b and c/d, compare them and return the greater. If they are equal, then return "equal".

Note: The string str contains "a/b, c/d"(fractions are separated by comma(,) & space( )). 

Examples

Input: str = "5/6, 11/45"
Output: 5/6
Explanation: 5/6=0.8333 and 11/45=0.2444, So 5/6 is greater fraction.
Input: str = "8/1, 8/1"
Output: equal
Explanation: We can see that both the fractions are same, so we'll return a string "equal".
Input: str = "10/17, 9/10"
Output: 9/10
Explanation: 10/17 = 0.588 & 9/10 = 0.9, so the greater fraction is "9/10".
Expected Time Complexity: O(len|str|)
Expected Auxiliary Space: O(1)

Constraints:
0<=a,c<=103
1<=b,d<=103
*/

class Solution {
 private:
 float calculate(string s){
     float ans = 0;
     string str="";
     for(int i = 0 ;  i<s.size();i++){
         if(s[i]=='/'){
             ans = stof(str);
             str="";
         }
         else {
             str+=s[i];
         }
     }
     ans = ans/stof(str);
     return ans;
 }
  public:
    string compareFrac(string str) {
        // Code here
        string s1 =""  , s2="";
        int count = 0;
        for(int i = 0 ;  i<str.size();i++){
            if(str[i]==',' || str[i]==' '){
                count++;
                continue;
            }
            if(count==0){
                s1+=str[i];
            }
            if(count==2){
                s2+=str[i];
            }
            
            
        }
        
        float n1 = calculate(s1) , n2 = calculate(s2);
        if(n1>n2) return s1;
        else if(n1<n2) return s2;
        else return "equal";
        
    }
};