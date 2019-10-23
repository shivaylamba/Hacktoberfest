#include<stdio.h>

main()

{int a,b,c;
printf("enter the no. ");
scanf("%d%d%d",&a,&b,&c);
if((a>b)&&(a>c))
printf("%d",a);
if((b>a)&&(b>c))
printf("%d",b);
else
printf("%d",c);
}
