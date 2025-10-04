#include <iostream>
#include <vector>
using namespace std;

int productExceptPivot(vector<int>& nums, int pivot) {
    int product = 1;
    for(int i=0; i< nums.size(); i++) {
        if(nums[i] != pivot)
            product *= nums[i];
    }
    return product;
}

int main() {
    vector<int> nums = {1, 3, 5, 6, 2};
    int pivot = 5;
    cout << productExceptPivot(nums, pivot) << endl;
    return 0;
}
