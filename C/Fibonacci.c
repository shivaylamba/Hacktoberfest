// #include<stdio.h>    
// int main()    
// {    
//  int n1=0,n2=1,n3,i,number;    
//  printf("Enter the number of elements:");    
//  scanf("%d",&number);    
//  printf("\n%d %d",n1,n2);//printing 0 and 1    
//  for(i=2;i<number;++i)//loop starts from 2 because 0 and 1 are already printed    
//  {    
//   n3=n1+n2;    
//   printf(" %d",n3);    
//   n1=n2;    
//   n2=n3;    
//  }  
//   return 0;  
// }
#include <stdio.h>
#include <conio.h>
int fib_recursive(int n)
{
    if (n == 1 || n == 2)
    {
        return (n - 1);
    }
    else
    {
        return fib_recursive(n - 1) + fib_recursive(n - 2);
    }
}

int main()
{
    int x1;
    printf("Enter the position of Fibonacci series that you want to print : \n");
    scanf("%d", &x1);
    printf("The Fibonacci Number is %d \n", fib_recursive(x1));
    return 0;
}
