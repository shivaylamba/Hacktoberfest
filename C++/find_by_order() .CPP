// C++ program to implement find_by_order()

#include <bits/stdc++.h>

// Importing header files
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

// Declaring Ordered Set
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update>
	pbds;

// Driver Code
int main()
{
	
	int arr[] = {1, 5, 6, 17, 88};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	pbds S;
	
	// Traverse the array
	for (int i = 0; i < n; i++) {
		
		// Insert array elements
		// into the ordered set
		S.insert(arr[i]);
	}
	
	// Returns iterator to 0-th
	// largest element in the set
	cout << *S.find_by_order(0) << " ";
	
	// Returns iterator to 2-nd
	// largest element in the set
	cout << *S.find_by_order(2);

	return 0;
}
