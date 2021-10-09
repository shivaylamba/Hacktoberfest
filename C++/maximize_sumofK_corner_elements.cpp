// https://www.geeksforgeeks.org/maximize-sum-of-k-elements-in-array-by-taking-only-corner-elements/

#include <iostream>
#include <math.h>
using namespace std;

void sum(int A[], int K, int size);

int main() {
    int A[] = {8, 4, 4, 8, 12, 3, 2, 9}, K = 3;
    int size = sizeof(A)/ sizeof(int);
    sum(A, K, size);
	return 0;
}

void sum(int A[], int K, int size)
{
    int max_sum = 0, cur_sum = 0, N = K-1, end = size-1;
    for(int i=0; i<K; i++)
        cur_sum += A[i];
    
    max_sum = cur_sum;
    for(int i=0; i<K; i++)
    {
        cur_sum = cur_sum - A[N--] + A[end--];
        max_sum = max(max_sum, cur_sum);
    }
    cout<<max_sum;
}