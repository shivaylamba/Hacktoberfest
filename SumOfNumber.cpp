#include<iostream.h>
#include<conio.h>
void main()
{
int num,rem,sum=0;

//Asking for user input and storing in num
cout<<"Enter a number";
cin>>num;

while(num>0)
{
rem=num%10;
sum=sum+rem;
num=num/10;
}

//Displaying the sum
cout<<"The sum of digits is: "<<sum;
}
