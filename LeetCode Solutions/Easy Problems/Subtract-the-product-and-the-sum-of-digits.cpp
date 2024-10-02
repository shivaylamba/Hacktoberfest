#include<iostream>
using namespace std;
class Solution
{
public:
   int SubtractProductandSum(int n);
};
int  Solution::SubtractProductandSum(int n){
 int product=1,sum=0;
 int n1=n;
 while(n){
  int lastdigit=n%10;
  product*=lastdigit;
  sum+=lastdigit;
  n/=10;
 }
 cout<<"The number is : "<<n1<<"the products of digits is : "<<product<<"\nand the sum is : "<<sum<<"\nand the subtract of products and the sum of the digits is : "<<product - sum<<endl;

}
int main(){
    Solution obj1;
    int n;
    cin>>n;
    obj1.SubtractProductandSum(n);
}