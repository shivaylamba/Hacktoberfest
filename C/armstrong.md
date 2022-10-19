#include<stdio.h>
int main()
{
  inr num,r,sum=0,temp=0;
  printf("Enter the number : ");
  scanf("%d",&num);
  temp= num;
  while(num>0)
  {
    r=n%10;
    sum=sum + (r*r*r);
    n=n/10;
  }
  if(temp==sum)
  printf("It's an armstrong number.");
  else
  printf("Not an armstrong number.");
  
  return 0;
}
