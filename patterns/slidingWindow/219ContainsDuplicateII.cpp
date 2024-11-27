/*Given an integer array nums and an integer k, 
return true if there are two distinct indices i and j in the array 
such that nums[i] == nums[j] and abs(i - j) <= k.*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<int, int>map;
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        int i=0, j=0;
        while(j<nums.size()){
            if(map.find(nums[j]) != map.end()){
                if((abs(map[nums[j]] - j)) <= k){
                    return true;
                }
            }
            map[nums[j]] = j;
            j++;
        }
        return false;
    }
};

int main(){
    std::vector<int> nums = {1,0,1,1};
    Solution s;
    if(s.containsNearbyDuplicate(nums, 1)){
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }
}