#include<stdio.h>
int main()
{
	int n1,n2,o,s,a;
	printf("ENTER a number \n");
	scanf("%d",&n1);
		printf("ENTER another number \n");
scanf("%d",&n2);
printf("ENTER the operator of the operation you want \n");
	scanf(" %c",&o);
	
	switch(o)
	{
	case '+':
		printf("Addition result is = %d",n1+n2);
		break;
	case '-':
		if(n1>n2)
		{
			printf("Substraction result is = %d",n1-n2);
			break;
		}
			else
			{
				printf("Substraction result is= %d",n2-n1);
			break;
		}
	case '*':
			printf("Multiplication result is = %d",n1*n2);
			break;
	case '/':
			if(n1>n2)
			{
			printf("Division result is = %d",n1/n2);
			break;
		}
			else
			{
				printf("Division result is = %d",n2/n1);
			break;
		}
}
return 0;

}
