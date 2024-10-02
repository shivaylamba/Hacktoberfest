      //Approach -1// math and recursion

class Solution {
public:
    bool isPowerOfTwo(int n) {
       if(n==0){
           return 0;
       }   
       else if(n==1){
           return 1;
       }
       else{
           return n%2==0 && isPowerOfTwo(n/2);
       }
    }
};

