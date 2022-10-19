// Q.sort the elements in assending orders

#include <stdio.h>
#include <conio.h>
void main()
{
  int a[10], i, n, temp, j;
  printf("enter the range of an array:");
  scanf("%d", &n);
  printf("\nenter %d elements of the array:", n);
  for (i = 0; i < n; i++)
  {
    printf("\na[%d]:", i);
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
  printf("\n According to assending order sorted array is:");
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  getch();
}
/*
enter 5 elements of the array:
a[0]:6

a[1]:3

a[2]:2

a[3]:5

a[4]:1

 According to assending order sorted array is:1 2 3 5 6
 */
