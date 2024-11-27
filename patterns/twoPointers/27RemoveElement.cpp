#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int j=0, i=0, dup=0;
        while(j<nums.size()){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
            j++;
            
        }
        return i;
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {0,1,2,2,3,0,4,2};
    int k = s.removeElement(nums, 2);

    std::cout << "k: " << k << std::endl;
    for (const auto i : nums){
        std::cout << i << " ";
    }
}

