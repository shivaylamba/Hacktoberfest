#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]> target) end = end-1;
            else start = start+1;
        }
        return -1;
    }
};

int main(){
  vector<int> nums;
  int target;
  cin >> target;
  for(int i=0; i<nums.size(); i++){
    cin >> nums[i];
  }
  Solution object;
  object.search(nums, target);
  
  return 0;
}
