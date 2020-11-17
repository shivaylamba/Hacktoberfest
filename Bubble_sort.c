#include<stdio.h>

int main()
{
	
	int i,j,r,a[100];

	printf("Enter number of elements");

	scanf("%d", &r);

	for(i=0;i<r;i++)
	{
		printf("Enter a[%d]: ", i);
		scanf("%d", &a[i]);

	}

	for(i=0;i<r-1;i++)
	{
		for(j=0;j<r-1-i;j++)
		{
			if(a[j]>a[j+1])
			{	int t;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}


	printf("Sorted array:-\n");

	for(i=0;i<r;i++)
	{
		printf("%d ", a[i]);
	}
}
