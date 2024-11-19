/*594. Longest Harmonious Subsequence
We define a harmonious array as an array where the difference between its 
maximum value and its minimum value is exactly 1.
Given an integer array nums, return the length of its longest harmonious 
subsequence among all its possible subsequences.*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<int, int>map;
    int findLHS(std::vector<int>& nums) {
       int maxLen=0, len = 0;
       for (int i:nums){
            map[i]++;
       }
       
       for(const auto& pair:map){
        if(map.find((pair.first)+1) != map.end()){
            len = pair.second + map[(pair.first)+1];
            maxLen = std::max(maxLen, len);
        }
       }
       return maxLen;
    }
};

int main(){
    Solution s;
    std::vector<int>nums = {1,1,1,1};
    int lhs = s.findLHS(nums);

    std::cout << std::endl << "LHS: " << lhs << std::endl;
}