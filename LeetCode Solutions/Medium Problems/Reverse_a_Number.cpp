#include<bits/stdc++.h>
using namespace std;
#define SIZE(x) sizeof(x) * 8;
class Solution {
public:
    int reverse(int x) {
         long int rev =0;
         int range = SIZE(int);
        while(x){
            rev = rev*10 + (x%10);
           x/=10;
         if(rev < pow(-2, range - 1) || rev > pow(2, range - 1) ){
            return 0;
           }
        }
        return rev;
    }
};
int main(){
    Solution s1;
    int n;
    cin>>n;
    cout<<s1.reverse(n)<<endl;
}