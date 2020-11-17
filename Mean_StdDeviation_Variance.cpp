#include<stdio.h>
#include<math.h>

int main()
{

	float a[50],sum;
	int n,i;

	printf("\nEnter number of elements in your array\n");
	scanf("%d", &n);

	printf("\nEnter your array\n");

	for(i=0;i<n;i++)
	{

		printf("Enter element %d ", i+1);
		
		scanf("%d", &a[i]);
	}

	float mean,v,sd;
	mean=0;

	for(i=0;i<n;i++)
	{

		mean=mean+a[i];
	}

	mean=mean/n;

	sum=0;

	for(i=0;i<n;i++)
	{

		sum = sum+(pow(a[i]-mean,2));
	}

	v=sum/n;
	sd=pow(v,1/2);

	printf("\nMean= %d \nVariance= %d \nStandard Deviation= %d \n", mean, v, sd);

}
