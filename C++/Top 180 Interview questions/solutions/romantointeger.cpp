class Solution {
public:
    int romanToInt(string s) {
     unordered_map<char,int> um;
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        int sum = 0;
        int num = 0;
        int len = s.size();
        for(int i = 0 ; i < len ;)
        {
          if(i==len-1 || um[s[i]]>=um[s[i+1]])
          {
              num = um[s[i]];
              i++;
          }
            else
         {
           num = um[s[i+1]] - um[s[i]]; 
                i=i+2;
         }
            sum+=num;
        }
        return sum;
    }
};