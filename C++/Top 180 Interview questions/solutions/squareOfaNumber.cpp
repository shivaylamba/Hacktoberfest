int squarefunction(int num)
{
	num = abs(num);
	int temp_num = num;
	// assuming temp_num not crossing the limit
	int res = 0;
	int pos = 0;
	while(temp_num)
	{
		if(temp_num & 1)
		{
			res = res + (n<<pos);
		}
		pos++;
		temp_n>>=1;
	}
	return res;
}