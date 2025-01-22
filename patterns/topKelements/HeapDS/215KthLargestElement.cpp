// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
// Can you solve it without sorting?

#include <iostream>
#include <vector>
#include <queue>
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::priority_queue<int>pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        for(int i=0; i<k-1; i++){
            pq.pop();
        }
        return pq.top();
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {2,1};
    int n = s.findKthLargest(nums, 1);
    std::cout << std::endl << "Kth largest ele: " << n;
    return 0;
}