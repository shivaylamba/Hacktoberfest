int  k = 0;
for(int b = n / 2 ; b >=1 ; b/=2)
{
	while(k + b < n && arr[b+k]<=x) k+=b;
}
if(arr[k]==x)
	return k ;
// k is the index