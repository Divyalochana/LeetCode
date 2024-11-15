#include <iostream>
#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int len = nums.size();
        int i=0, j=1, dupCnt=0;

        for(; j<nums.size(); j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;
        
    }
};

int main(){
    Solution sol;
    std::vector<int> nums = {1,1,2};
    int k = sol.removeDuplicates(nums);
    std::cout << "k: " << k << std::endl;

    for(const auto i: nums){
        std::cout << i << " " << std::endl;
    }
}