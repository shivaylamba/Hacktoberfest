#include<iostream>
using namespace std;

int count=0;

void hanoi(int n,int src,int dest,int helper)
{
	if(n==0)
		{
			return;
		}

hanoi(n-1,src,helper,dest);
cout<<"Move "<<" disc "<<n<< " from T"<<src<<" to T"<<dest<<endl;
count++;
hanoi(n-1,helper,dest,src);
}

int main()
{
	int n;
	cin>>n;
	hanoi(n,1,2,3);
	cout<<count;
	return 0;

}