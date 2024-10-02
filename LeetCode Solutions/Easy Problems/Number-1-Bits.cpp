#include<iostream>
using namespace std;
class Solution
{
public:
   int number_1_bits(uint32_t n);
};
int  Solution::number_1_bits(uint32_t n){
            int counter=0;
       while(n!=0){
         if(n&1){
            counter++;
         }
        n = n>>1;
       }
       return counter;
    }
int main(){
    Solution obj1;
    uint32_t n;
    cin>>n;
   cout<< obj1.number_1_bits(n);
}