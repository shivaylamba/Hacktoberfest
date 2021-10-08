// C++ program to find the number of islands using DFS

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int N,int M,int i,int j)
{
	if(i < 0 || i >= N)
		return false;
	if(j < 0 || j >= M)
		return false;
	return true;
}

void delIsland(int **A,int N,int M,int i,int j)
{
	if(isSafe(N,M,i,j) && A[i][j] == 1)
		{
			A[i][j] = 0;
			delIsland(A, N , M , i-1, j-1);
			delIsland(A, N, M, i-1, j);
			delIsland(A, N, M, i-1, j+1);
			delIsland(A, N, M, i, j-1);
			delIsland(A, N, M, i, j+1);
			delIsland(A, N, M, i+1, j-1);
			delIsland(A, N, M, i+1, j);
			delIsland(A, N, M, i+1, j+1);
		}
}

int TotalBridge(int **A, int N, int M)
{
	int count = 0 ;
	for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
				if(A[i][j] == 1)
					{
						count++;
						delIsland(A,N,M,i,j);
					}
		}
	if(count == 0)
		return 0;
	return count;
}


int main()
{
	int N,M;
	cout << “nEnter the order of the islands : “;
	cin >> N >> M;
	int **A = (int **)malloc(N * sizeof(int *));
	for (int i = 0; i < N; i++)
		A[i] = (int *)malloc(M * sizeof(int));
	cout << “nEnter the island matrix : n”;
	for(int i = 0; i < N ; i++)
		for(int j = 0; j < M; j++)
			cin >> A[i][j];
	cout << “Total Number of islands : ” << TotalBridge(A,N,M)<<endl;
	return 0;
}
