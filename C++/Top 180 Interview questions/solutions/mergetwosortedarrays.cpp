void merge ( int arr1[], int arr2[])
{
	 // n is the size of the arr1
	// m is the size of the arr2
	int x = n - 1;
	int y = 0 ; 
	while(x > = 0 && y < m)
	{
		if(arr1[x] > arr2[y]){
			swap(arr1[x], arr2[y]);
			x--;
			y++;
		}
		else
			break;
	}
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + m);
}


// 	// code for kadane's algorithm
// int maxSubArray(vector<int>& nums)
// {
// 	int ans = nums[0];
// 	int sum = 0 ;
// 	for( int i = 0 ; i < nums.size(); i++)
// 	{
// 		sum +=nums[i];
// 		ans = max(ans,sum);
// 		sum = max(sum, 0);
// 	}
// 	return ans;
// }