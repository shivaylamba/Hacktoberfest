#include <stdio.h>
	int add(int n);
	void main()
	{
		int n;
		printf("Enter the number:");
		scanf("%d",&n);
		printf("Sum is %d",add(n));
	}
int add(int n)
{if(n!=0)
return n+add(n-1);
}
