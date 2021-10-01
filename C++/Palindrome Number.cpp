class Solution {
public:
    bool isPalindrome(int x) {
        long long int y,n=0,t=x;
        while(x!=0)
        {
            y=x%10;
            n=n*10+y;
            x=x/10;
        }
        if(t>=0) return t==n;
        else return false;
            
    }
};
