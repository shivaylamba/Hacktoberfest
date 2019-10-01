// C++ program to print largest contiguous array sum 
#include<iostream> 
#include<climits> 
using namespace std; 

int maxSubArraySum(int a[], int size) 
{ 
	int max_so_far = INT_MIN, max_ending_here = 0; 

	for (int i = 0; i < size; i++) 
	{ 
		max_ending_here = max_ending_here + a[i]; 
		if (max_so_far < max_ending_here) 
			max_so_far = max_ending_here; 

		if (max_ending_here < 0) 
			max_ending_here = 0; 
	} 
	return max_so_far; 
} 

int maxSum_minSum(int arr[],int size){ // To find maximum continguous subarray sum using minimum subarray sum till an index in O(N)
	int min_sum = 0, max_sum = INT_MIN, cur = 0;
	
    	for(int i = 0;i < size;i++){
        	cur += arr[i];
        	max_sum = max(max_sum,cur - min_sum);
        	min_sum = min(cur,min_sum);
    	}
	
    	return max_sum;
}

/*Driver program to test maxSubArraySum*/
int main() 
{ 
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
	int n = sizeof(a)/sizeof(a[0]); 
	int max_sum = maxSubArraySum(a, n); 
	int max_sum2 = maxSum_minSum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	cout << "\nMaximum continguous sum found using minimum sum is " << max_sum2;
	return 0; 
} 
