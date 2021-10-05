class Solution {
public:
    void remove(string& s , int& len)
    {
    for(int i = 0 ; i < s.length() ; i++)
    {
       if(s[i]=='#')
       {
           if(len > 0)
               len --;
       }
       else
           s[len++] = s[i]; 
    }
    }
    bool backspaceCompare(string s, string t) {
        int lens = 0;
        int lent = 0;
        remove(s,lens);
        remove(t,lent);
        if(lens!=lent)
            return false;
        for(int i = 0 ; i < lens ; i++)
        {
            if(s[i]!=t[i])
                return false;
        }
        return true;
    }
};