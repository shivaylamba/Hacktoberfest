#include<stdio.h>

int main()
{

	int n,a[50],no;
	int i;

	printf("\nEnter number of elements in your array: ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		printf("\nEnter element %d: ", i+1);
		scanf("%d", &a[i]);
	}

	printf("\nEnter the number whose occurence is to be found \n");
	scanf("%d", &no);

	int o=0;

	for(i=0;i<n;i++)
	{
		if(a[i]==no)
		{
			o=o+1;
		}
	}

	printf("\nFrequency = %d", o);

}
