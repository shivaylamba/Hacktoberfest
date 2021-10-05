class Solution {
public:
    int trailingZeroes(int n) {
     int t = 5;
     int count = 0;
        while(t <= n){
           count+=(floor(n/t));
            t=t*5;
        }
        return count;
    }
};