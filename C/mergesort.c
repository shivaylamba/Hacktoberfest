#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int p, int r)
{
  // finding size of the list between indices p and r
  int n = r-p+1;
  // dividing the list into 2 parts
  int q = (p+r)/2;
  // declaring a new array to store the sorted list
  int *b = (int *)malloc(sizeof(int)*n);
  int left = p, right = q+1, k = 0;
  while(left <= q && right <= r)
  {
    if(a[left] <= a[right])
      b[k++] = a[left++];
    else
      b[k++] = a[right++];
  }
  // copying remaining elements to b
  while(left <= q)
  b[k++] = a[left++];
  while(right <= r)
  b[k++] = a[right++];
  // copying elements of b back to a
  int i;
  k = 0;
  for(i = p; i <= r; i++)
  a[i] = b[k++]; 
}

void merge_sort(int *a, int p, int r)
{
  if(p < r)
  {
    int q = (p+r)/2; // divide step
    merge_sort(a,p,q);
    merge_sort(a,q+1,r);
    merge(a,p,r);
  }
}

void display(int *a, int n)
{
  int i;
  for(i = 0; i < n; i++)
  printf("%d ",*(a+i));
}

main()
{
  int n,i;
  printf("Enter size of the array : ");
  scanf("%d",&n);
  int *a = (int *)malloc(sizeof(int)*n);
  printf("Enter %d numbers in the array : ",n);
  for(i = 0; i < n; i++)
  scanf("%d",(a+i));
  merge_sort(a,0,n-1);
  printf("Sorted List : ");
  display(a,n);
}