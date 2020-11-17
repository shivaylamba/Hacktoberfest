#include<stdio.h>
#include<conio.h>
void main()
{
int N;
scanf("%d", &N); /*The value of N is taken as input from the test case */

	int i=0;
	// pyramid of stars
	while(N!=0)
	{
		while(i!=N)
		{
			printf("*");
			i++;
		}
		i=0;
		printf("\n");
		N--;
	}
getch();
}