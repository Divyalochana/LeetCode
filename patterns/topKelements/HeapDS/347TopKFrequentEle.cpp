// Given an integer array nums and an integer k, return the k most frequent elements. 
// You may return the answer in any order.

#include <iostream>
#include <vector>
#include<unordered_map>
#include <queue>
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int>mp;
        std::vector<int> res;
        for(int i:nums){
            mp[i]++;
        }  

        std::priority_queue<std::pair<int, int>, std::vector<std::pair <int, int>>, std::greater<>> minHeap;
        for(const auto &pair: mp){
            minHeap.push({pair.second, pair.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        while (!minHeap.empty())
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
        
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {1,1,1,2,2,3};
    std::vector<int>res = s.topKFrequent(nums, 2);
    for(int i:res){
        std::cout << i << " ";
    }
}