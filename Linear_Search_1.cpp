#include<stdio.h>

int main()
{

	int a[10];

	int i;

	for(i=0;i<10;i++)
	{
		printf("Enter %d element", i+1);

		scanf("%d", &a[i]);
		
	}

	int n;

	printf("Enter the number to be found");

	scanf("%d", &n);

	int f=0;

	for(i=0;i<10;i++)
	{

		if(n==a[i])
		{
			printf("Found at %d position", i+1);
			f=1;
		}
	}

	if(f==0)
	{
		printf("Not Found");

	}

}
