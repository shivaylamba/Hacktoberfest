// leetcode premium string shifts
int Solution:: shifts(string se ,vector<vector<string>> s)
{
	for(vector<int> pp : s)
	{
		if(pp[0] == 0)
			total-=pp[1];
		else
			total+=pp[1];
	}
	int n = se.length();
	if(total < n)
		total+=n;
	total = total % n;
	return se.substr(n-total) + s.substr(0,n-total);

	// in right shift we bring elements from last to first
}