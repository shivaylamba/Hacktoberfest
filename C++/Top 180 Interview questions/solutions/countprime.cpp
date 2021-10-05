class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1)
            return 0;
        int count = 0 ;
            bool prime[n+1];
        memset(prime, true, sizeof(prime));
        //memset can take -1, or 1, it workd byte by byte
        for(int i = 2; i*i <= n ; i++){
            if(prime[i]==true)
            {
               
            for(int p = i*i ; p <= n; p+=i){
                prime[p]=false;
            }
            }
        }
        for(int i = 2 ;  i <=n ; i++)
            if(prime[i]==true)
                count++;
        if(prime[n]==true)
            count--;
        return count;
    }
};