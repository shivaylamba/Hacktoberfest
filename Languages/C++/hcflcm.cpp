#include<iostream>
using namespace std;
int main()
{
int num1,num2,onum1,onum2,lcm;
cout<<"enter num";
cin>>num1>>num2;
onum1=num1;
onum2=num2;
while(num1%num2!=0)
{
int rem=num1%num2;
num1=num2;
num2=rem;	
}
int hcf=num2;
lcm=(num1*num2)/hcf;
cout<<"hcf is"<<hcf<<endl;
cout<<"lcm is:"<<lcm;	
return 0;	
}
