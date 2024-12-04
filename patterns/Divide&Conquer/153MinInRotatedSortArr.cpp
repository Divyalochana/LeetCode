#include <iostream>
#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int low = 0, high = nums.size()-1, mid =0, min = INT_MAX;
        while (low<=high)
        {
            mid = (low+high)/2;
            if(nums[mid] < min){min = nums[mid];}

            if(nums[low] < nums[mid] & nums[low] < min){
                min = nums[low];
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return min;
        
    }
};

int main(){
    std::vector<int> nums = {11,13,15,17};
    Solution s;
    int min = s.findMin(nums);
    std::cout << "min:" << min;
    return 0;
}