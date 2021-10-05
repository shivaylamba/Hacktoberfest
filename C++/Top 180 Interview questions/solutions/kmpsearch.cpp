int main()
{
	string pattern;
	string txt;
	int n = pattern.size();
	int m = txt.size();
	while(i < n)
	{
		if(pat[i]==txt[j])
		{
			i++;
			j++;
		}
		if(j==m)
			cout << "pattern found at index" << i - j;
		else if(i < n && pat[i]!=txt[j])
		{
			if(j!=0)
				j = lps[j-1];
			else
				i++;
		}
	}
}