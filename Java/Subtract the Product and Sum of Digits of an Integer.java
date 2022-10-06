class Solution {
    public int subtractProductAndSum(int n) {
        int sum = 0; 
        int product= 1;
        while(n!=0){
            int r=n%10;
            sum += r ;
            product *=r;
            n= n/10;
        }
        int diff = product- sum ;
       return diff;
    }
}
