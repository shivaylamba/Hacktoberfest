class Solution {
public:
    int nthUglyNumber(int n) {
       // a perfect solution using dp
        if(n<=0) return false;
        // same as returning 0;
        if(n==1) return 1;
        // base case;
        vector<int> k(n);
        k[0]=1;
        int t1=0;
        int t2=0;
        int t3=0; // these are the indexes for 2, 3, 5
        // minimum element would be 2 *(1,2,3), 3 *(1,2,3), 5*(1,2,3)... considering
        // that the 1 2 3 are the set of first three triplets
        for(int i = 1 ; i< n ; i++){
        k[i] = min(k[t1]*2,min (k[t2]*3,k[t3]*5));
            if(k[i]==k[t1]*2) t1++;
            if(k[i]==k[t2]*3) t2++;
            if(k[i]==k[t3]*5) t3++;
            }
        return k[n-1];
    }
};