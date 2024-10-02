class Solution {
public:
    int getSum(int a, int b) {
        // First Approach
        // for(int i =1;i<=b;i++){
        //     a++;
        // }
        // return a;
        return (int)log2(pow(2,a)*pow(2,b));
    }
};