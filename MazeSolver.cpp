#include<iostream>
using namespace std;

bool issafe(int**maze, int x, int y, int n)
{
    if (x<n && y<n && maze[x][y]==1)
    {return true ;}

    return false ;
}

bool mazesolver(int**maze, int x, int y, int n, int**solmaze)
{
    if (x==n-1 && y==n-1)
    {
        solmaze[x][y]=1;
        return true;
    }

    if (issafe(maze,x,y,n))
    {
        solmaze[x][y]=1;

        if(mazesolver(maze,x+1,y,n,solmaze))
        {return true;}

        if(mazesolver(maze,x,y+1,n,solmaze))
        {return true;}
    
        solmaze[x][y]=0;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int**maze=new int*[n];
    for (int i=0;i<n;i++)
    {
        maze[i]=new int[n];
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }
    int**solmaze=new int*[n];
    for (int i=0;i<n;i++)
    {
        solmaze[i]=new int[n];
        for (int j=0;j<n;j++)
        {
            solmaze[i][j]=0;
        }
    }
    if(mazesolver(maze, 0, 0, n, solmaze))
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                cout<<solmaze[i][j]<<" ";
            }cout << endl;
        }
    }
    else
    cout << "No solution found" ;

    return 0;
}
//6
//1 1 1 0 1 1
//1 0 1 1 1 0
//1 1 0 1 0 1
//0 1 0 1 1 1
//0 1 1 0 1 0
//0 1 0 0 1 1