class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      // here the prefix bole toh sirf starting me hi rahega
      // okay?
        int n = strs.size();
        int minsize=1000;
         int count = 0;
        string s;
        // one suggestion you can initialize the string with no initialization as well
        for(int i = 0 ; i< n; i++)
        {
            int Size = strs[i].size();
            if(Size<minsize)
            {
                minsize = Size;
                s = strs[i];
            }
        }
        for(int i = 0 ; i < minsize; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(strs[j][i]!=s[i])
                    return s.substr(0, count);
            }
            count++;
        }
        return s.substr(0,count);
    }
};