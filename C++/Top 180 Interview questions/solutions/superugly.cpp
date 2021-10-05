class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // will use the same approach as in the previous problem
        // just here instead of 2 3 5 we have a array of prime numbers soo...
        int size = primes.size();
        vector<int>pos(size,0);
        // the above is same as what we took t1, t2 ,t3 for the 2 3 5
        vector<int> res(n);
        res[0]=1;
        for(int i = 1 ; i<n ; i++)
        {
        int temp=INT_MAX;
            //can't be directly assigned to res[i];
            // last question it was k[i];
            for(int j = 0 ; j<size ; j++){
            temp = min(temp, res[pos[j]] * primes[j]);
            }
            for(int j = 0 ; j< size ; j++){
            if(temp==(res[pos[j]] * primes[j]))
                pos[j]++;
            }
            res[i]=temp;
        }
        return res[n-1];
    }
};