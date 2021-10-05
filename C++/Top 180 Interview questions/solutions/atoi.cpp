class Solution {
public:
    int myAtoi(string s) {
      int len = s.size();
      int check = 1;
      int i = 0;
        while(i < len && s[i]==' ')
            i++;
        if(i==len)
            return 0;
        if(s[i]=='-'){
            check = 0;
            i++;
        }
        else if(s[i]=='+')
        {
            i++;
        }
        // need to consider the + sign as well
        long int out = 0;
        // might go out of bond so to prevent integer overflow
        while(s[i]>='0' && s[i]<='9')
        {
           out = out * 10;
            if(out <= INT_MIN || out >=INT_MAX)
                break;
            out+=s[i]-'0';
            i++;
        }
        if(check==0)
            out = -1 * out;
        if(out<=INT_MIN)
            return INT_MIN;
        if(out>=INT_MAX)
           return INT_MAX;
          return (int)out;
    }
};