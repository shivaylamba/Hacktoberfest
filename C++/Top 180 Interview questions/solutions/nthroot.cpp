double multiply(double num , double m)
{
	double ans = 1.0;
	for(int i = 1 ; i <=m ; i++)
	{
		ans = ans * num;
	}
	return ans;
}

double getnthroot(double n , double m)
{
	double low = 1 ;
	double high = m;
	double eps = 1e-6;
	// as we want to have it uptil  decimal places

	while((high - low) > eps)
	{
		double mid = (low + high) / 2.0 ;
		if(multiply(mid,n) < m)
			low = mid;
		else 
			high = mid;
	}
}

int main()
{
	int n , m;
	cin >> n >> m ;
	getnthroot(n,m);
	return 0;
}