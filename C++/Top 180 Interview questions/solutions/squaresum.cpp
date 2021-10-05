class Solution {
public:
    bool judgeSquareSum(int c) {
     // so here we will run the loop for the value of a or b
    // b2=c - a2;
       // hence the value of a wouuld range from 0 to root(c);
        for(long i = 0 ; i * i <= c; i++){
        double x = sqrt(c - (i*i));
            if(x==(int)x)
                return true;
        }
        return false;
    }
};