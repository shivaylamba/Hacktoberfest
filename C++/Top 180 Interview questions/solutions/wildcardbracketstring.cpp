class Solution {
public:
    bool checkValidString(string s) {
        int bal = 0 ;
        const int n = s.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i]=='(' || s[i]=='*')
                bal++;
            else if(--bal == -1)
                return false;
        }
        bal = 0 ;
        for(int i = n-1 ; i>=0 ; i--)
        {
            if(s[i]==')' || s[i]=='*')
                bal++;
            else if(--bal == -1)
                return false;
        }
        return true;
    }
};