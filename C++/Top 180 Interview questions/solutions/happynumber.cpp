class Solution {
public:
    int func(int n)
    {
        int sum = 0;
        while(n){
        int dig = n % 10;
        n/=10;
        sum+=(dig * dig);
            }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while(true)
        {
         if(n==1)
             return true;
         n = func(n);
         if(s.count(n)==1)
             return false;
         s.insert(n);
        }
    }
};