#include<iostream>
using namespace std;
class Solution
{
public:
//   Most OPtimized 
  bool isPalindrome(int x) {
    if (x < 0)
      return false;

    long reversed = 0;
    int y = x;

    while (y) {
      reversed = reversed * 10 + y % 10;
      y /= 10;
    }

    return reversed == x;
  }
// least Optimized
    bool isPalindrome(int x) {
       if(x==0){
           return 1;
       }
        long int rev=0,n=x;
      while(x>0){
        rev = rev*10 + (x%10);
        x/=10;
       if(rev == n){
            return 1;
        }
      }
            return 0;
   }
};
int main(){
    Solution obj1;
    int n;
    cin>>n;
   cout<< obj1.isPalindrome(n);
}