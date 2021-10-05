class Solution {
public:
    int strStr(string main, string submain) {
        int n = main.size();
        int m = submain.size();
        if(n==0 && m==0)
            return 0;
        else if(m==0)
            return 0;
        else if(n==0)
            return -1;
        // using the naive approach to find the index of the substring
        for(int i = 0; i < n ; i++)
        {
            int j = 0;
            for(; j < m ; j++)
            {
                if(main[i+j]!=submain[j])
                    break;
            }
            if(j==m)
             return i;
        }
        return -1;
    }
};