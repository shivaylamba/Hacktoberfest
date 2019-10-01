#include <stdio.h>

void rotate(int A[], int n)
{
   int t = A[n-1], i;
   for (i = n-1; i > 0; i--)
      A[i] = A[i-1];
   A[0] = t;
}

int main()
{
    int n;
    scanf("%d",&n);
    int A[n],i;
     for (i = 0; i < n; i++)
        scanf("%d",&A[i]);

    rotate(A, n);

    printf("\nThe rotated array is : \n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
