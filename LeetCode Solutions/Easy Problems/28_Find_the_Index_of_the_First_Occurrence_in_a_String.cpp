class Solution {
public:
// Most Optimized
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
        
    }
// optimized
        int strStr(string haystack, string needle) {
        int n = needle.size();
        if(haystack.size()<n){
            return -1;
        }
        string str;
        for(int i=0; i<haystack.size(); i++){
            if(needle[0]==haystack[i]){
                str = haystack.substr(i, n);
                if(str == needle){
                    return i;
                }
            }
        }
        return -1;
    }
// least Optimized
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        string s ;
        for(int i = 0 ; i<n;i++){
            s = "";
            for(int j =1;j<=n-i;j++){
                s = haystack.substr(i,j);
                if(s==needle){
                    return i;
                }
            }
        }
        return -1;
    }
};