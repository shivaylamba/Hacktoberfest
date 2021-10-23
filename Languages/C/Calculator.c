#include<stdio.h>
int main()
{
	int n1,n2,o,s,a;
	printf("ENTER 2 NO. =");
	scanf(" %d %d",&n1,&n2);
		printf("ENTER operator =");
	scanf(" %c",&o);
	
	switch(o)
	{
	case '+':
		printf("Addition value = %d",n1+n2);
		break;
	case '-':
		if(n1>n2)
		{
			printf("Substraction value = %d",n1-n2);
			break;
		}
			else
			{
				printf("Substraction value = %d",n2-n1);
			break;
		}
	case '*':
			printf("Multiplication value = %d",n1*n2);
			break;
	case '/':
			if(n1>n2)
			{
			printf("Substraction value = %d",n1/n2);
			break;
		}
			else
			{
				printf("Substraction value = %d",n2/n1);
			break;
		}
}
return 0;

}
