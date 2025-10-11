#include<stdio.h>
#include<math.h>
int main()
{
	int n1,n2;
	char o;
	printf("ENTER operator(+,-,*,/,r,%,^)= ");
	scanf(" %c",&o);
	if(o =='r'){
		printf("enter number= ");
		scanf("%d",&n1);
		printf("square root value of %d=%.2f\n",n1,sqrt(n1));
	}
	else{
	printf("ENTER 2 NO. = ");
	scanf(" %d %d",&n1,&n2);
	
	switch(o)
	{
	case '+':
		printf("Addition value = %d\n", n1+n2);
		break;
	case '-':
		printf("Subtraction value = %d\n", n1-n2);
		break;
	case '*':
		printf("Multiplication value = %d\n", n1*n2);
		break;
	case '/':
		if(n2!=0)
		printf("division value = %.2f\n", (float)n1/n2);
		else
        printf("Error!\n");
		break;
	case '%':
		if(n2!=0)
		printf("Modulus value=%d\n", n1%n2);
		else
        printf("Error!\n");
		break;
	case '^':
		printf("power value=%.2f\n", pow(n1,n2));
		break;
	default:printf("Invalid operator!!\n");		
		}
	
}
return 0;

}
