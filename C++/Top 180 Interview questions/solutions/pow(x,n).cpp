class Solution {
public:
    double myPow(double x, int n) {
       // so we will divide the case into two for the odd and the even power
       // also for the negative and the positive cases
       double ans = 1.0;
        // as it can be a decimal so intialzing it in the same way only
        long long nn = n;
        if(nn < 0) nn = -1 * nn;
        // just making it positive
        
        while(nn)
        {
            // if the power is odd
            if(nn % 2)
            {
                ans = ans * x;
                nn = nn -1;
            }
            else
            {
                x = x*x;
                nn/=2;
            }
        }
        // the above is called the type casting
        if(n < 0) ans = (double) 1.0 / (double) ans;
        return ans;
    }
};