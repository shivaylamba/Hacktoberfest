class Solution {
   private boolean helper(int n, HashSet<Integer> set){
    int sum=0;
    if(n==1)
        return true;
    else{
        if(set.contains(n))
            return false;
        else{
                set.add(n);
                while(n>0){ 
                int digit=n%10;
                sum+=digit*digit;
                n=n/10;
            }
          //  set.add(sum);
            return helper(sum, set);
        }
    }
   }

    public boolean isHappy(int n) {
       HashSet<Integer> set=new HashSet<>();
       return helper(n, set);
    }
}
