#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::unordered_map<int, int> map;
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        int i=0, j=k-1;
        long long sum = 0, calc=0;
        for(int it = i; it<=j; it++){
            map[nums[it]]++;
            calc += nums[it];
        }
        std::cout << "calc: " << calc << std::endl;
        if(map.size() == k){
            sum = std::max(calc, sum);
        }

        while(j<nums.size()-1){
            j++;
            map[nums[i]]--;
            map[nums[j]]++;
            calc = (calc-nums[i])+nums[j];
            std::cout << calc << std::endl;
            if(map[nums[i]] == 0){
                map.erase(nums[i]);
            }
            if(map.size() == k){
                sum = std::max(calc, sum);
            }
            i++;
        }
        return sum;
    }
};

int main(){
    std::vector<int> nums = {1,5,4,2,9,9,1};
    Solution s;
    int sum = s.maximumSubarraySum(nums, 3);

    std::cout << "sum: " << sum;
}