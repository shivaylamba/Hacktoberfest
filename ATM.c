#include<stdio.h>
int main()
{
  int withdraw;
  float balance;
  scanf(" %d",&withdraw );
  scanf(" %f",&balance );
  if(withdraw%5==0 && balance-withdraw-0.5>=0)
   printf("%.2f\n",balance-withdraw-0.5 );
  else
    printf("%.2f\n",balance );
  return 0;
}

