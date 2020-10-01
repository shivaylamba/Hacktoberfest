
#include <iostream> 
using namespace std; 


int subArraySum(int arr[], int n, int sum) 
{ 

	int curr_sum = arr[0], start = 0, i; 

	/* Add elements one by one to curr_sum and 
	if the curr_sum exceeds the sum, 
	then remove starting element */
	for (i = 1; i <= n; i++) 
	{ 
	
		while (curr_sum > sum && start < i - 1) 
		{ 
			curr_sum = curr_sum - arr[start]; 
			start++; 
		} 


		if (curr_sum == sum) 
		{ 
			cout << "Sum found between indexes "
				<< start << " and " << i - 1; 
			return 1; 
		} 

		if (i < n) 
		curr_sum = curr_sum + arr[i]; 
	}  
	cout << "No subarray found"; 
	return 0; 
}  
int main() 
{ 
	int arr[] = {15, 2, 4, 8, 9, 5, 10, 23}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int sum = 23; 
	subArraySum(arr, n, sum); 
	return 0; 
} 

