// You are given an integer array nums consisting of n elements, 
// and an integer k. Find a contiguous subarray whose length 
// is equal to k that has the maximum average value and 
// return this value. Any answer with a calculation error less 
// than 10-5 will be accepted.

#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double maxAvg = INT_MIN, avg=0;
        for(int i=0; i<k; i++){
            avg += nums[i];
        }
        maxAvg = avg/k;

        int j=0;
        for(int i=k; i<nums.size(); i++){
            avg = (avg - nums[j])+nums[i];
            maxAvg = std::max(maxAvg, avg/k);
            j++;
        }
        return maxAvg;
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {7,4,5,8,8,3,9,8,7,6};
    double avg = s.findMaxAverage(nums, 7);

    std::cout << "MaxAverage: " << avg;
}