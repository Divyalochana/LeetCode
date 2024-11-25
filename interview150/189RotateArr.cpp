// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        if(k==0) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end()+k);
        reverse(nums.begin()+k, nums.end());  
    }
};

int main(){
    std::vector<int>nums = {1,2};
    Solution sol;
    sol.rotate(nums, 2);
    for(int i:nums){
        std::cout << i << " ";
    }
}
