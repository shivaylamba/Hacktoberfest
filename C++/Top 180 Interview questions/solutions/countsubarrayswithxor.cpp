int Solution::solve(vector<int>& A, int B)
{
	map<int, int> freq;
	int count = 0;
	int xor = 0;
	for(auto it: A)
	{
		xor = xor ^ it;
		if(xor==B)
			count++;
		if(freq.find(xor^B)!=freq.end())
		{
			count+=(freq(xor^B));
		}
		freq[xor]+=1;
	}
	return count;
}