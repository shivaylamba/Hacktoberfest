#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	long MaxProduct(vector<int> &nums)
	{
		long first = 0, second = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > first)
			{
				second = first;
				first = nums[i];
			}
			else if (nums[i] > second)
			{
				second = nums[i];
			}
		}
		return first*second;
	}
};




int main() {
	vector<int> vec;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		vec.push_back(x);
	}

	Solution s;
	cout << s.MaxProduct(vec) << endl;
	
	return 0;
}
