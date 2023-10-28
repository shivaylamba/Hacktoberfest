class Solution {
    public boolean isHappy(int n) {
        int sum=0;
        do
        {
            do
            {
                int d=n%10;
                sum=d*d+sum;
                n=n/10;
            }while(n>0);
            n=sum;
            sum=0;
        } while(n>9);
        if(n==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    } 
}
