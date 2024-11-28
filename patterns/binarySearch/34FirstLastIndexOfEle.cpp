/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int start = findStart(nums, target);
        int end = findEnd(nums, target);
        return {start, end};
    }
private:
    int findStart(std::vector<int> &nums, int target){
        int res = -1;
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                res = mid;
                high = mid-1;
            }else if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return res;
    }

    int findEnd(std::vector<int> &nums, int target){
        int res = -1;
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                res = mid;
                low = mid+1;
            }else if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return res;
    }
    
};

int main(){
    std::vector<int> nums = {5,7,7,8,8,10};
    Solution s;
    std::vector<int>res = s.searchRange(nums, 2);
    for(int i: res){
        std::cout << i << " ";
    }
    return 0;
}