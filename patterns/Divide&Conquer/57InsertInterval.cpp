#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {

        int i=0;
        std::cout << "i: " << i << std::endl;
        while(i<intervals.size() && (intervals[i][0] < newInterval[0])){i++;}
        std::cout << "i: " << i << std::endl;
        intervals.insert(intervals.begin()+i, newInterval);
        for(const auto& row:intervals){
            for(const auto &j: row){
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "-------" << std::endl;
        std::vector<std::vector<int>>res;
        
        for(const auto& ele: intervals){
            if(res.empty() || res.back()[1] < ele[0]){
                res.push_back(ele);
            }else{
                res.back()[1] = std::max(res.back()[1], ele[1]);
            }
        }
        return res;  
    }
};

int main(){
    std::vector<std::vector<int>> nums = {{2,6}, {7,9}};
    std::vector<int>newNum = {15,18};

    Solution s;
    std::vector<std::vector<int>>res = s.insert(nums, newNum);

    for(const auto& row:res){
        for(const auto &j: row){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}