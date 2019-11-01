#include<stdio.h>

int main()
{

	int a[50],b[50],c[100];
	int i,n1,n2;

	printf("\nEnter number of elements in array 1: ");
	scanf("%d", &n1);

	printf("\nEnter your sorted array 1");
	
	for(i=0;i<n1;i++)
	{
		printf("\nEnter %dst element: ", i+1);

		scanf("%d", &a[i]);
	}

	printf("\nEnter number of elements in array 2: ");
	scanf("%d", &n2);

	printf("\nEnter your sorted array 2");
	
	for(i=0;i<n2;i++)
	{
		printf("\nEnter %dst element: ", i+1);

		scanf("%d", &b[i]);
	}

	int k=0;
	int j=0;
	i=0;


	while(i<n1&&j<n2)
	{

		if(a[i]>b[j])
		{
			c[k++]=b[j++];
		}

		else if(a[i]<b[j])
		{

			c[k++]=a[i++];
		}
		
		else
		{
			c[k++]=a[i++];
			c[k++]=b[j++];
		}
	
	}

	while(i<n1)
	{
		c[k++]=a[i++];
	}	

	while(j<n2)
	{
		c[k++]=a[j++];
	}	
	


	printf("\nNew merged array\n");
	
	for(i=0;i<(n1+n2);i++)	
	{
		printf("%d", c[i]);
	}

}