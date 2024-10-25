class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for (char c: s){
            if (isalpha(c) || isdigit(c)) 
            ans.push_back(tolower(c));
        }
        
        int i=0,j=ans.size()-1;
        while(i<=j){
            if (ans[i]!=ans[j]){
                return false;
                break;
            }
            i++;
            j--;
        }
        return true;
    }
};
