#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n = nums.size();
    for(int num : nums) {
        freq[num]++;
        if(freq[num] > n / 2)
            return num;
    }
    return -1;
}

int main() {
    vector<int> nums = {3, 2, 3};
    cout << majorityElement(nums) << endl;
    return 0;
}
