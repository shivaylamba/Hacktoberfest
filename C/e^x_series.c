#include<stdio.h>
int main(){
  float x,term,sum;
  int n,count;
  printf("Enter the value of x");
  scanf("%f",&x);
  printf("Enter the term till the sum has to be found");
  scanf("%d",&n);
  sum=0;
  term=1;
  for(count=1;count<=n;count++){
    sum=sum+term;
    term=term*x/count;

  }
  printf("%f",sum);
  return 0;			
    
}