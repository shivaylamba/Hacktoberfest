class Solution {
public:
    string countAndSay(int n) {
       if(n==1) return "1";
       if(n==2) return "11";
        string s = "11";
        for(int i = 3; i<=n; i++)
        {
            // string for storing the next
             string t;
            s+="$";
            // we are putting the delimeter
            // so that we can hhave the count of
            // the last digit
             int cnt = 1;
            for(int j = 1 ; j<s.length(); j++)
            {
               if(s[j]!=s[j-1])
               {
                    t+=to_string(cnt);
                     t+=s[j-1];
                    cnt=1;
               }
                else
                    cnt++;
            }
            s=t;
            // we had to return the nth iterated value
        }
        return s;
    }
};